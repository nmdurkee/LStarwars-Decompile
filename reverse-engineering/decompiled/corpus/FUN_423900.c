/* Ghidra analysis pseudocode, not original source.
 * ev_8e49f0d7b7d603436767358480d73156eb2c225a9905dada8633f81c37eed0ad
 * Entry: 0x423900; label: FUN_00423900
 */

void FUN_00423900(int param_1)

{
  int iVar1;
  
  if (param_1 != 1) {
    FUN_004f8c20(&DAT_0086e500,&DAT_0086e500);
    iVar1 = FUN_004f1ff0(&DAT_0086e500);
    if (iVar1 < 0xf) {
      _memset((void *)((int)&DAT_0086e500 + iVar1),0x20,0xf - iVar1);
    }
    DAT_0086e50f = 0;
  }
  if (param_1 != 0) {
    FUN_004f8c20(&DAT_0086e538,&DAT_0086e538);
    iVar1 = FUN_004f1ff0(&DAT_0086e538);
    if (iVar1 < 0xf) {
      _memset(&DAT_0086e538 + iVar1,0x20,0xf - iVar1);
    }
    DAT_0086e547 = 0;
  }
  return;
}

