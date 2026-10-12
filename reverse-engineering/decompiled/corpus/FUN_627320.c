/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x627320; label: FUN_00627320
 */

undefined4 FUN_00627320(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (DAT_02912e88 != 0) {
    if (DAT_02912e8c != 0) {
      if (((*(int *)(DAT_02912e8c + 0x10) != 0) && (*(int *)(DAT_02912e8c + 0x14) != 0)) ||
         (*(int *)(DAT_02912e8c + 0x20) == 0)) {
        uVar2 = FUN_0061f440();
        return uVar2;
      }
      DAT_02912e8c = 0;
    }
    if (0 < DAT_02910ca4) {
      do {
        iVar1 = FUN_006272a0();
        if (iVar1 != 0) {
          return 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < DAT_02910ca4);
    }
  }
  return 0;
}

