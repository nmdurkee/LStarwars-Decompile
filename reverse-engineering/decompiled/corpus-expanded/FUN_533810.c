/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x533810; label: FUN_00533810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00533810(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  if (((*(byte *)(unaff_EDI + 0x92) & 0x80) == 0) &&
     (iVar1 = FUN_005cfac0(DAT_009238e4 + 0x3c), iVar3 = DAT_009238e4, iVar1 != 0)) {
    *(undefined4 *)(unaff_EDI + 0x98) = *(undefined4 *)(DAT_009238e4 + 0x3c);
    *(undefined4 *)(unaff_EDI + 0x9c) = *(undefined4 *)(iVar3 + 0x40);
    *(undefined4 *)(unaff_EDI + 0xa0) = *(undefined4 *)(iVar3 + 0x44);
    uVar2 = FUN_005d0330(DAT_009238e4 + 0x3c);
    FUN_005b33c0(unaff_EDI + 0xa4,unaff_EDI + 0x18,uVar2);
  }
  else {
    *(undefined4 *)(unaff_EDI + 0x98) = 0;
    *(undefined4 *)(unaff_EDI + 0x9c) = 0;
    *(undefined4 *)(unaff_EDI + 0xa0) = 0;
  }
  FUN_0052a2f0();
  FUN_00522100();
  if (DAT_009238f0 != (code *)0x0) {
    (*DAT_009238f0)(*(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20));
  }
  if (*(int *)(unaff_EDI + 0xb0) != 0) {
    for (iVar3 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar3 != 0;
        iVar3 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar3)) {
      for (iVar1 = FUN_004f1440(iVar3 + 0x18); iVar1 != 0; iVar1 = FUN_004f1460(iVar3 + 0x18,iVar1))
      {
        if ((iVar1 != unaff_EDI) && (*(int *)(iVar1 + 0xb0) == *(int *)(unaff_EDI + 0xb0))) {
          *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)(unaff_EDI + 0x18);
          *(undefined4 *)(iVar1 + 0x1c) = *(undefined4 *)(unaff_EDI + 0x1c);
          *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(unaff_EDI + 0x20);
          *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(unaff_EDI + 0x24);
          *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(unaff_EDI + 0x28);
          *(undefined4 *)(iVar1 + 0x2c) = *(undefined4 *)(unaff_EDI + 0x2c);
          *(undefined4 *)(iVar1 + 0x98) = *(undefined4 *)(unaff_EDI + 0x98);
          *(undefined4 *)(iVar1 + 0x9c) = *(undefined4 *)(unaff_EDI + 0x9c);
          *(undefined4 *)(iVar1 + 0xa0) = *(undefined4 *)(unaff_EDI + 0xa0);
          *(undefined4 *)(iVar1 + 0xa4) = *(undefined4 *)(unaff_EDI + 0xa4);
          *(undefined4 *)(iVar1 + 0xa8) = *(undefined4 *)(unaff_EDI + 0xa8);
          *(undefined4 *)(iVar1 + 0xac) = *(undefined4 *)(unaff_EDI + 0xac);
          FUN_0052a2f0(iVar1);
          FUN_00522100(iVar1);
          break;
        }
      }
    }
  }
  return;
}

