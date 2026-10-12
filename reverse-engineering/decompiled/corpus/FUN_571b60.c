/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x571b60; label: FUN_00571b60
 */

void FUN_00571b60(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((((param_1 != 0) && (-1 < param_2)) && (param_2 < DAT_00950ff8)) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 8) + param_2 * 0x14), iVar1 != -1)) {
    FUN_0064b370(iVar1,param_3,1);
  }
  return;
}

