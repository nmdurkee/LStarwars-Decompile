/* Ghidra analysis pseudocode, not original source.
 * ev_0d1e553906e4ac29f0c898728bb3c9cf38177ab98ca2cbcdea8e6b852723dd83
 * Entry: 0x59e720; label: FUN_0059e720
 */

void FUN_0059e720(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_00956430 < 0x20) {
    iVar1 = FUN_004f9e70(param_1);
    if (iVar1 < 0) {
      FUN_0059e450();
      return;
    }
    *(int *)(&DAT_00956350 + DAT_00956430 * 4) = iVar1;
    DAT_00956430 = DAT_00956430 + 1;
  }
  return;
}

