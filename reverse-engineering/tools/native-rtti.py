"""Bounded MSVC x86 RTTI and vtable recovery from original initialized PC sections."""
import json,struct,hashlib
from pathlib import Path
BASE=Path(__file__).resolve().parent.parent;blob=(BASE/'binary/LEGOStarWarsSaga.packed.exe.unpacked.exe').read_bytes();pe=json.loads((BASE/'reports/unpacked-pe/pe.json').read_text());strings=json.loads((BASE/'reports/unpacked-pe/strings.json').read_text());imagebase=pe['imageBase']
def offset(va,size=4):
 for s in pe['sections']:
  n=va-imagebase-s['rva']
  if n>=0 and n+size<=s['size']:return s['offset']+n
 raise ValueError('Pointer outside initialized image '+hex(va))
def words(va,count):return struct.unpack_from('<'+'I'*count,blob,offset(va,count*4))
def signed(v):return v if v<0x80000000 else v-0x100000000
def intext(v):return any(s['name']=='.text' and imagebase+s['rva']<=v<imagebase+s['rva']+s['size'] for s in pe['sections'])
types={s['va']-8:{'descriptor':hex(s['va']-8),'name':s['text'],'nameAddress':hex(s['va']),'typeInfoVftable':hex(words(s['va']-8,1)[0])} for s in strings if s['text'].startswith(('.?AV','.?AU'))}
hierarchies={};locators={};rejected=[]
def hierarchy(va):
 if va in hierarchies:return hierarchies[va]
 signature,attrs,count,array=words(va,4)
 if signature!=0 or attrs>7 or not 1<=count<=1024:raise ValueError('Invalid hierarchy header')
 rows=[]
 for p in words(array,count):
  td,contained,mdisp,pdisp,vdisp,flags=words(p,6)
  if td not in types or contained>count or flags>0xff:raise ValueError('Invalid base descriptor')
  rows.append({'descriptor':hex(p),'typeDescriptor':hex(td),'name':types[td]['name'],'containedBases':contained,'mdisp':signed(mdisp),'pdisp':signed(pdisp),'vdisp':signed(vdisp),'attributes':flags})
 h={'address':hex(va),'signature':signature,'attributes':attrs,'baseCount':count,'baseArray':hex(array),'bases':rows};hierarchies[va]=h;return h
for s in pe['sections']:
 if s['name'] not in ['.rdata','.data']:continue
 for p in range(s['offset'],s['offset']+s['size']-19,4):
  sig,objoff,cdoff,td,hier=struct.unpack_from('<IIIII',blob,p)
  if td not in types or sig!=0 or objoff>1048576 or cdoff>1048576:continue
  va=imagebase+s['rva']+p-s['offset']
  try:
   h=hierarchy(hier)
   if h['bases'][0]['typeDescriptor']!=hex(td):raise ValueError('Top base disagrees with locator type')
   locators[va]={'address':hex(va),'offset':p,'objectOffset':objoff,'constructorDisplacement':cdoff,'typeDescriptor':hex(td),'name':types[td]['name'],'hierarchy':hex(hier)}
  except ValueError as e:rejected.append({'address':hex(va),'reason':str(e)})
# These six adjacent data boundaries were inspected in the original image.
# Short ASCII/UTF16 words can numerically fall inside .text; they are not pointers.
data_boundaries={0x7642cc:'UTF16 bloom/dof',0x7654bc:'ASCII fnt',0x76a8b4:'ASCII CPU',0x76ac54:'ASCII NOS',0x76ac98:'ASCII FTP',0x76b264:'ASCII Res followed by PROC'}
vftables=[]
for s in pe['sections']:
 if s['name'] not in ['.rdata','.data']:continue
 for p in range(s['offset'],s['offset']+s['size']-7,4):
  col=struct.unpack_from('<I',blob,p)[0]
  if col not in locators:continue
  va=imagebase+s['rva']+p-s['offset']+4;slots=[];termination='first-pointer-outside-initialized-text'
  for i in range(512):
   if va+i*4 in data_boundaries:
    termination='observed-adjacent-data: '+data_boundaries[va+i*4];break
   try:target=words(va+i*4,1)[0]
   except ValueError:break
   if not intext(target):break
   slots.append({'slot':i,'slotAddress':hex(va+i*4),'target':hex(target),'initialCorpus':'decompiled/corpus/FUN_'+format(target,'x')+'.c' if (BASE/'decompiled/corpus'/('FUN_'+format(target,'x')+'.c')).exists() else None,'expandedCorpus':'decompiled/corpus-expanded/FUN_'+format(target,'x')+'.c' if (BASE/'decompiled/corpus-expanded'/('FUN_'+format(target,'x')+'.c')).exists() else None,'supplementalCorpus':'decompiled/corpus-supplemental/FUN_'+format(target,'x')+'.c' if (BASE/'decompiled/corpus-supplemental'/('FUN_'+format(target,'x')+'.c')).exists() else None})
  if slots:vftables.append({'address':hex(va),'locator':hex(col),'className':locators[col]['name'],'objectOffset':locators[col]['objectOffset'],'slots':slots,'termination':'512-slot-limit' if len(slots)==512 else termination})
report={'binarySha256':hashlib.sha256(blob).hexdigest(),'reference':'https://github.com/llvm/llvm-project/blob/main/clang/lib/CodeGen/MicrosoftCXXABI.cpp','scope':'32-bit absolute-pointer MSVC RTTI in initialized .rdata/.data only','counts':{'typeDescriptors':len(types),'locators':len(locators),'hierarchies':len(hierarchies),'vftables':len(vftables),'slots':sum(len(v['slots']) for v in vftables),'uniqueTargets':len({x['target'] for v in vftables for x in v['slots']}),'rejectedLocatorCandidates':len(rejected)},'observedDataBoundaries':[{'address':hex(v),'description':d,'originalBytes':blob[offset(v,32):offset(v,32)+32].hex()} for v,d in data_boundaries.items()],'types':list(types.values()),'locators':list(locators.values()),'hierarchies':list(hierarchies.values()),'vftables':vftables,'rejected':rejected,'limits':['Names are original mangled RTTI strings, not manually renamed functions.','Non-polymorphic/no-RTTI classes and runtime-generated tables can be absent.','Vtable slot extent ends at observed adjacent data or first non-text pointer and is a bounded candidate sequence, not a universal proof of the class virtual-method count.','Subobject offsets and PMD triples describe inheritance adjustment, not complete instance field layouts.','No constructors, destructors or virtual calls were executed.']}
(BASE/'reports/native-rtti.json').write_text(json.dumps(report,indent=2)+'\n');print(json.dumps(report['counts']));print(json.dumps([v for v in vftables if v['address'] in ['0x7e9320','0x7e93a4']],indent=2))
