/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x4247d0; label: FUN_004247d0
 */

int FUN_004247d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = (&DAT_008568f0)[param_1];
  if (iVar2 != 1) {
    if (iVar2 != 0) {
      do {
        iVar1 = iVar2 + 1;
        iVar2 = 0;
      } while (iVar1 % 3 == 0);
    }
    return (int)DAT_00880760;
  }
  return (int)DAT_00880870;
}

