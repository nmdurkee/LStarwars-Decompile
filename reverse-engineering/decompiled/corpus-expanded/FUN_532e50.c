/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x532e50; label: FUN_00532e50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00532e50(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_2 != 0) {
    for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x4874); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x4874,iVar1)) {
      if (*(int *)(param_2 + 0xc) == iVar3) {
        *(int *)(DAT_009238e4 + 0x4868) = iVar1;
        uVar2 = FUN_00522a00(0);
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24) = uVar2;
        *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x20) =
             *(undefined4 *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24);
        iVar3 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x24);
        if (iVar3 != 0) {
          FUN_00620f10(iVar3 + 0x18);
        }
        break;
      }
      iVar3 = iVar3 + 1;
    }
  }
  if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}

