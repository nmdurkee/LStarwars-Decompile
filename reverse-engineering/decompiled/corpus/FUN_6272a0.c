/* Ghidra analysis pseudocode, not original source.
 * ev_82613852739bd66c0ef0ae4a5b7138b98fa59042d44f2c612a65801f1499c980
 * Entry: 0x6272a0; label: FUN_006272a0
 */

undefined4 FUN_006272a0(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_ESI;
  int unaff_EDI;
  undefined8 uVar5;
  
  uVar2 = DAT_02912ec8;
  uVar4 = 0;
  if ((unaff_EDI == *(int *)(unaff_ESI + 0x10)) &&
     ((*(uint *)(unaff_ESI + 0x1c) & DAT_02912ec8) != 0)) {
    uVar5 = FUN_0061f4b0();
    iVar3 = (int)((ulonglong)uVar5 >> 0x20);
    if ((int)uVar5 != 0) {
      uVar4 = 1;
      if (((iVar3 != 0) && (iVar1 = *(int *)(unaff_ESI + 0x14), iVar1 != 0)) &&
         (*(int *)(iVar1 + 8) != 0x12)) {
        *(int *)(iVar3 + 8) = iVar1;
      }
      if (*(int *)(unaff_ESI + 0x20) == 0) {
        if ((*(uint *)(unaff_ESI + 0x1c) & DAT_02912ec4) == 0) {
          return 1;
        }
        if (unaff_EDI != DAT_02912eac) {
          FUN_006271a0();
        }
      }
      else if ((*(uint *)(unaff_ESI + 0x1c) & uVar2) == 0) {
        return 1;
      }
      if ((*(code **)(unaff_ESI + 0x18) != (code *)0x0) &&
         (iVar3 = (**(code **)(unaff_ESI + 0x18))(), iVar3 != 0)) {
        DAT_02912e8c = unaff_ESI;
      }
    }
  }
  return uVar4;
}

