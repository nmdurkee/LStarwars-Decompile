/* Ghidra analysis pseudocode, not original source.
 * ev_b2ae0094aac4233f18363a226dc902c019a1728ce7ff5cc7e95ded3ed7c5c2a8
 * Entry: 0x68b7f0; label: FUN_0068b7f0
 */

void FUN_0068b7f0(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_02921884 != -1) {
    iVar1 = *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14);
    if (iVar1 != DAT_02962a10) {
      *(int *)(DAT_02921884 * 0x50 + 4 + DAT_02962a14) = iVar1 + 1;
      FUN_0068b220(iVar1,param_1);
    }
  }
  return;
}

