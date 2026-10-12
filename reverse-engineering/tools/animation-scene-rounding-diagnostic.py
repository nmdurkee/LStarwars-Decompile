from pathlib import Path
exec((Path(__file__).parent/'animation-scene-native-verify.py').read_text().split('inventory=json.loads')[0])
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
d=Cs(CS_ARCH_X86,CS_MODE_32)
for i in d.disasm(bytes(mu.mem_read(0x5ce6b0,850)),0x5ce6b0):
 if i.mnemonic.startswith('f'):
  print(hex(i.address),i.mnemonic,i.op_str)
  if i.op_str.startswith('dword ptr [0x')or i.op_str.startswith('qword ptr [0x'):
   addr=int(i.op_str.split('[0x')[1].split(']')[0],16);size=4 if i.op_str.startswith('dword')else 8
   print(' constant',struct.unpack('<f'if size==4 else'<d',mu.mem_read(addr,size)))
source='LEVELS/EPISODE_II/PURSUIT/PURSUIT_A/PURSUIT_A_PC.GSC';a=json.loads((BASE/'exports/animation-scenes'/(source+'.json')).read_text())['animations'][224];raw=(BASE/'extracted'/source).read_bytes();h=a['header'];o=a['sourceOffset'];prepare(raw[o:o+h['flagsOffset']+20]);print('original scalars',run(79,0,9)[0])
