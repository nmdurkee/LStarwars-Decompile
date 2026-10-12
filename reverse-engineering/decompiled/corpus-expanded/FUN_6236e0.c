/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x6236e0; label: FUN_006236e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006236e0(undefined4 param_1)

{
  int iVar1;
  char local_104;
  undefined1 local_103 [255];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_104;
  local_104 = '\0';
  _memset(local_103,0,0xff);
  FUN_004f1f10(&DAT_02912f50,param_1);
  iVar1 = FUN_004f1fc0(&DAT_02912f50,0x2e);
  if (iVar1 != 0) {
    iVar1 = FUN_004f1fc0(&DAT_02912f50,0x5c);
    if (iVar1 == 0) {
      FUN_004f1f10(&local_104,param_1);
      DAT_02912f50 = 0;
    }
    else {
      FUN_004f1f10(&local_104,(undefined1 *)(iVar1 + 1));
      *(undefined1 *)(iVar1 + 1) = 0;
    }
  }
  if (local_104 == '\0') {
    DAT_02913060 = 0;
    __security_check_cookie(local_4 ^ (uint)&local_104);
    return;
  }
  FUN_004f7cf0(&DAT_02913060,&local_104,0xff);
  __security_check_cookie(local_4 ^ (uint)&local_104);
  return;
}

