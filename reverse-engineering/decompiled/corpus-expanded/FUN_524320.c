/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x524320; label: FUN_00524320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00524320(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar1 != 0;
      iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
    for (iVar2 = FUN_004f1440(iVar1 + 0x18); iVar2 != 0; iVar2 = FUN_004f1460(iVar1 + 0x18,iVar2)) {
      iVar3 = FUN_005cfac0(iVar2 + 0x98);
      if (iVar3 != 0) {
        uVar4 = FUN_005d0330(iVar2 + 0x98);
        FUN_005b30a0(iVar2 + 0x18,iVar2 + 0xa4,uVar4);
      }
    }
  }
  return;
}

