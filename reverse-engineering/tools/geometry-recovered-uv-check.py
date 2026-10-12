"""Compile/run recovered C# UV core and compare its binary output with original PC instructions."""
import importlib.util,json,struct,hashlib,base64,subprocess,argparse
from pathlib import Path
P=Path(__file__).resolve().parent;B=P.parent;OUT=B/'reconstructed/geometry';REPORT=B/'reports';sp=importlib.util.spec_from_file_location('nx',P/'native-x86.py');nx=importlib.util.module_from_spec(sp);sp.loader.exec_module(nx)
parser=argparse.ArgumentParser(description=__doc__)
parser.add_argument('--harness',type=Path,default=OUT/'GeometryUvHarness.exe',help='Normally compiled console harness path; relative to current working directory.')
parser.add_argument('--assembly',type=Path,default=OUT/'Recovered.Geometry.dll',help='Core assembly used by the harness, recorded for provenance.')
parser.add_argument('--module',choices=['geometry'],help='Prefix required when using the unified RecoveredSourceVerify.exe.')
options=parser.parse_args()
from unicorn import UC_HOOK_CODE
from unicorn.x86_const import UC_X86_REG_ESP,UC_X86_REG_EIP
cases=json.loads((REPORT/'geometry-uv-programs.json').read_text());fixtures=bytearray(struct.pack('<Ii',0x31565547,len(cases['configurations'])))
for c in cases['configurations']:
 fixtures+=base64.b64decode(c['rawRecordBase64'])+struct.pack('<?i',c['member'],len(c['scenarios']))
 for s in c['scenarios']:
  fixtures+=struct.pack('<fi',s['timeBefore'],len(s['steps']))
  fixtures+=b''.join(struct.pack('<f',x['delta'])for x in s['steps'])
wrappers=[(reset,speed)for reset in [False,True]for speed in [0,.5,1,-2]];fixtures+=struct.pack('<i',len(wrappers))+b''.join(struct.pack('<?f',*x)for x in wrappers)
fi=OUT/'harness/fixtures.bin';fo=OUT/'harness/output.bin';fi.write_bytes(fixtures)
subprocess.run([str(options.harness.resolve())]+([options.module]if options.module else[])+[str(fi),str(B/cases['sineTable']['file']),str(fo)],check=True)
output=fo.read_bytes();pos=4;assert struct.unpack_from('<i',output)[0]==len(cases['configurations'])
n=nx.NativeX86();n.write(0x29899a0,(B/cases['sineTable']['file']).read_bytes());SET=n.DATA;SCENE=SET+0x100;INDEX=SET+0x200;TABLE=SET+0x300;MAT=SET+0x1000
n.pack('<4I',SET,SCENE,1,INDEX,0);n.pack('<I',INDEX,0);n.pack('<I',SCENE+0x50,TABLE);n.pack('<I',TABLE,MAT)
def hook(mu,address,size,data):
 if address in [0x4ffaa0,0x4ffac0]:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
n.mu.hook_add(UC_HOOK_CODE,hook);ticks=0;scalars=0;exact=0;zeroSign=0;maxerr=0;errors=[]
def compare(native,recovered,context):
 global scalars,exact,zeroSign,maxerr
 for i in range(len(native)//4):
  a=struct.unpack_from('<f',native,i*4)[0];b=struct.unpack_from('<f',recovered,i*4)[0];e=abs(a-b)/max(1,abs(a),abs(b));scalars+=1;maxerr=max(maxerr,e)
  if native[i*4:i*4+4]==recovered[i*4:i*4+4]:exact+=1
  elif a==0 and b==0:zeroSign+=1
  if e>1e-7 and len(errors)<30:errors.append({'context':context,'slot':i,'native':a,'recovered':b,'error':e})
for c in cases['configurations']:
 raw=base64.b64decode(c['rawRecordBase64']);n.pack('<I',0x973fa8,SET if c['member'] else 0)
 for s in c['scenarios']:
  n.write(MAT,raw);n.pack('<f',0x97add0,s['timeBefore'])
  for step in s['steps']:
   n.call(0x5dfbd0,[struct.unpack('<I',struct.pack('<f',step['delta']))[0]])
   native=n.read(MAT+0x1d0,32)+n.read(0x97add0,4);compare(native,output[pos:pos+36],c['key']);pos+=36;ticks+=1
assert struct.unpack_from('<i',output,pos)[0]==len(wrappers);pos+=4;wrapperResults=[]
for reset,speed in wrappers:
 delta=.03125;n.pack('<I',0x973fa8,0);n.pack('<I',0x9739b8,2);n.pack('<I',0x80e9e4,reset);n.pack('<f',0x80bac4,speed);n.pack('<f',0x97add0,8);n.pack('<f',0x28571e8,12)
 for j in range(2):
  scene=n.DATA+0x5000+j*0x2000;header=scene+0x100;table=scene+0x400;mat=scene+0x500
  n.pack('<I',0x9739bc+j*4,scene);n.pack('<I',scene+0x78,header);n.pack('<I',header+0x158,j);n.pack('<I',scene+0x4c,1);n.pack('<I',scene+0x50,table);n.pack('<I',table,mat);n.pack('<8f',mat+0x1d0,*[.125*(k+1)for k in range(8)])
 n.call(0x601330,[struct.unpack('<I',struct.pack('<f',delta))[0]])
 native=b''.join(n.read(n.DATA+0x5000+j*0x2000+0x500+0x1d0,32)for j in range(2))+n.read(0x97add0,4)+n.read(0x28571e8,4)
 compare(native,output[pos:pos+72],'wrapper-'+str((reset,speed)));pos+=72;nativeReset=n.unpack('<I',0x80e9e4)[0]!=0;actualReset=bool(output[pos]);pos+=1;wrapperResults.append({'reset':reset,'speed':speed,'resetFlagMatch':actualReset==nativeReset})
assert pos==len(output)
r={'binarySHA256':n.sha256,'module':'reconstructed/geometry/MaterialUv.cs','moduleSHA256':hashlib.sha256((OUT/'MaterialUv.cs').read_bytes()).hexdigest(),'assemblySHA256':hashlib.sha256(options.assembly.read_bytes()).hexdigest(),'harnessSHA256':hashlib.sha256(options.harness.read_bytes()).hexdigest(),'compiler':'Installed .NET Framework64 v4.0.30319 csc.exe; dependency-free C# core and separate harness.','sineTable':cases['sineTable'],'authoredMaterials':cases['materialCount'],'authoredConfigurations':cases['uniqueAuthoredConfigurations'],'syntheticConfigurations':cases['syntheticConfigurations'],'nativeTicks':ticks,'nativeWrapperCases':len(wrappers),'scalarComparisons':scalars,'floatBitExactComparisons':exact,'signedZeroOnlyDifferences':zeroSign,'maxNormalizedError':maxerr,'passed':not errors and all(x['resetFlagMatch'] for x in wrapperResults),'errors':errors,'wrapperCases':wrapperResults,'fixtureSHA256':hashlib.sha256(fixtures).hexdigest(),'outputSHA256':hashlib.sha256(output).hexdigest(),'scope':'Compiled portable C# results compared directly with fresh execution of original0x5dfbd0 and0x601330. Only original critical-section calls stubbed; original math and setter execute. No original process or graphics APIs.','limits':['Core operates decoded bounded records and caller-provided state; it does not recreate frame scheduling, GPU uploads or scene registration.','Integer conversion phases outside the validated signed32 domain are rejected; processor-dependent overflow behavior is not guessed.']}
(REPORT/'geometry-recovered-uv-validation.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(r,indent=2))
