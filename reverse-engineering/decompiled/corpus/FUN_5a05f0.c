/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a05f0; label: FUN_005a05f0
 */

int FUN_005a05f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_3 != 0) {
    iVar1 = FUN_00552670(param_1,param_2,0x1c);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x10) = param_3;
      *(int *)(iVar1 + 0x14) = param_4;
      if (*(int *)(param_4 + 8) < DAT_00956618) {
        *(int *)(*(int *)(param_4 + 0xc) + *(int *)(param_4 + 8) * 4) = iVar1;
        *(int *)(param_4 + 8) = *(int *)(param_4 + 8) + 1;
      }
    }
  }
  return iVar1;
}

