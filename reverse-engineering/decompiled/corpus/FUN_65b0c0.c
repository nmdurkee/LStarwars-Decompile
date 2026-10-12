/* Ghidra analysis pseudocode, not original source.
 * ev_72b4c015fc5ea067bd8ff7b23618dfd066d3174eed64a8765571f91528d681aa
 * Entry: 0x65b0c0; label: FUN_0065b0c0
 */

void FUN_0065b0c0(undefined4 param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_24;
  _sprintf(local_24,"This is slot %d",*(undefined4 *)(param_2 + 0xc));
  iVar1 = FUN_00543c10(*(undefined4 *)(param_2 + 0xc),local_24,0x20);
  if (iVar1 == 0) {
    pcVar2 = "Save Error";
  }
  else {
    pcVar2 = "Saved OK";
  }
  FUN_00628d80(param_1,pcVar2,iVar1 != 0);
  __security_check_cookie(local_4 ^ (uint)local_24);
  return;
}

