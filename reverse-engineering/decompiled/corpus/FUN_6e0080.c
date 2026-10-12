/* Ghidra analysis pseudocode, not original source.
 * ev_64710b70227263f531e000337bf3c7b84d0ba3dbee751b1080463e073dfde27a
 * Entry: 0x6e0080; label: FUN_006e0080
 */

void FUN_006e0080(undefined4 param_1,char *param_2)

{
  code *pcVar1;
  
  if (param_2 != (char *)0x0) {
    _vsprintf(&DAT_0297b698,param_2,&stack0x0000000c);
  }
  _sprintf(&DAT_0297ae98,"\n%s\n",&DAT_0297b698);
  MessageBoxA(DAT_00924864,&DAT_0297ae98,"Fatal Error!",0x10);
  _raise(0x16);
  __exit(3);
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

