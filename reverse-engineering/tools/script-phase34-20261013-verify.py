"""Actual program→STATE→CONDITIONS→expression/token/bank pipeline. Final file and symbol services only for this route."""
from pathlib import Path
exec(Path(__file__).with_name('script-phase33-20261013-verify.py').read_text().split('\nfor name,existing')[0])
n=nm.NativeX86();stateCommand=command31
def command31(callback,model):
 if callback==0x52b3f0:materialize()
 else:stateCommand(callback,model)
def hook34(mu,address,size,data):
 if address==0x4fb550:hook26(mu,address,size,data)
 elif address in[f for p,f,name in commands+stateCommands if f not in[0x513540,0x5133f0,0x5136c0,0x513730,0x52b3f0]]+[FALLBACK,SECONDARY]:
  sp=mu.reg_read(UC_X86_REG_ESP);leaf33(address,False);ret=n.unpack('<I',sp)[0];mu.reg_write(UC_X86_REG_EAX,0x12345678);mu.reg_write(UC_X86_REG_ESP,sp+4);mu.reg_write(UC_X86_REG_EIP,ret)
 elif address in[CB,0x512850,0x512860,0x512870,0x4ef790]:
  sp=mu.reg_read(UC_X86_REG_ESP);ret=n.unpack('<I',sp)[0]
  if address==0x512850 and ret in[0x5135ba,0x513755]:count=0 if ret==0x5135ba else 1;events.append(dict(name='Diagnostic',callback=address,args=list(n.unpack('<'+'I'*count,sp+4))))
  else:hook25(mu,address,size,data)
n.mu.hook_add(UC_HOOK_CODE,hook34)
files=['STATE BASE\nCONDITIONS\nIF Timer > 1 goto BASE\n}\n}\n','PARAM 0 alpha 3\nCONST LIMIT 2\nSTATE first\nCONDITIONS\nIF Param alpha == LIMIT goto BASE and\nIF AlwaysTrue == 1\n}\n}\nSTATE BASE\nCONDITIONS\nIF Timer >= \"missing+2\" goto first KeepBlockedMessages\n}\n}\n','STATE first\nCONDITIONS\nIF Timer \"a b\" != 2\nIF GotOpponent < -0\n}\nACTIONS\nREFERENCESCRIPT\n}\n','STATE \"a b\"\nCONDITIONS\nIF Timer > \"1 +2\"\n}\n}\n','STATE BASE\nCONDITIONS\nIF missing > 3\n}\n}\n','STATE BASE\nCONDITIONS\nIF Timer\n}\n}\n','STATE BASE\nCONDITIONS\nIF Timer > 1\nIF Timer > 2 and\nIF Timer > 3 goto UNKNOWN\n}\n}\n','STATE BASE\nCONDITIONS\n'+''.join('IF '+r['name']+' == 1\n'for r in builtin)+'}\n}\n']
for file,chunk,handled in itertools.product(files,[1,17,4096],[False,True]):execute33(dict(file=file,chunk=chunk,depth=-1,callback=True,handled=handled),'Pipeline')
for mode,failAfter in itertools.product([0,1,2],[0,5,20,45]):execute33(dict(file=files[4],chunk=1,depth=-1,mode=mode,failAfter=failAfter),'Pipeline')
for bankSize in[0,36,37,64,96,128,256]:execute33(dict(file=files[0],bankSize=bankSize,depth=-1),'Pipeline')
report=dict(binarySha256=n.sha256,nativeCases=len(cases),nativeChecks=checks,mismatches=len(errors),errors=errors[:2],faultCases=sum(c['fault']for c in cases),managedExecution=False,newEntries=0,ports=['4fb550 finalfile bytes','9238c0 game expression symbols','remaining action/reference/macro/include/derive callbacks outside conditionroute'],closure='5137a0→513540→52b3f0+513230/5132f0/513100/512ea0+actualreaderhelpers')
(nm.BASE/'reports/script-phase34-20261013-tests.json').write_text(json.dumps(report,indent=2));(nm.BASE/'reports/script-phase34-20261013-native-fixtures.json').write_text(json.dumps(dict(binarySha256=n.sha256,cases=cases),separators=(',',':')));print(json.dumps({k:v for k,v in report.items()if k!='errors'}))
