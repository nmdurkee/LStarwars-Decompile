"""Preserve raw PC hold callback absent from the existing pseudocode corpus."""
import importlib.util,hashlib,json
from pathlib import Path
s=importlib.util.spec_from_file_location('n',Path(__file__).with_name('native-x86.py'));native=importlib.util.module_from_spec(s);s.loader.exec_module(native)
from capstone import Cs,CS_ARCH_X86,CS_MODE_32
n=native.NativeX86();raw=n.read(0x428f20,0x44);decoder=Cs(CS_ARCH_X86,CS_MODE_32)
records=[{'address':hex(i.address),'bytes':i.bytes.hex(),'mnemonic':i.mnemonic,'operands':i.op_str}for i in decoder.disasm(raw,0x428f20)]
report={'binarySha256':n.sha256,'function':'0x428f20','size':len(raw),'bytesSha256':hashlib.sha256(raw).hexdigest(),'rawHex':raw.hex(),'registrationEvidence':'decompiled/corpus/FUN_42e160.c assigns global0x955598=0x428f20; evidence ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57','instructions':records}
(native.BASE/'reports/animation-context-hold-callback-assembly.json').write_text(json.dumps(report,indent=2));print('Wrote',len(records),'original instructions')
