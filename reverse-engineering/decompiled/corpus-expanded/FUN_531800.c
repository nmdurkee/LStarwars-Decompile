/* Ghidra pseudocode, not original source.
 * ev_f14574f1686883c8a991ff5dcc30f6c2e407e48e229a0065a53ff25a44d38981
 * Entry: 0x531800; label: FUN_00531800
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00531800(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0xc) == 0) {
      *(undefined4 *)(DAT_009238e4 + 0x41208) = 0;
    }
    else {
      iVar2 = 1;
      for (iVar1 = FUN_004f1440(DAT_009238e4 + 0x41200); iVar1 != 0;
          iVar1 = FUN_004f1460(DAT_009238e4 + 0x41200,iVar1)) {
        if (*(int *)(param_2 + 0xc) == iVar2) {
          if (*(int *)(DAT_009238e4 + 0x41208) != iVar1) {
            *(int *)(DAT_009238e4 + 0x41208) = iVar1;
            if (*(int *)(DAT_009238e4 + 0x41208) == 0) {
              *(undefined4 *)(DAT_009238e4 + 0x3cbe0) = 0;
            }
            else {
              *(undefined4 *)(DAT_009238e4 + 0x3cbe0) =
                   *(undefined4 *)(*(int *)(DAT_009238e4 + 0x41208) + 0x18);
              if ((*(int *)(DAT_009238e4 + 0x3cbe0) != 0) &&
                 (*(undefined4 *)(DAT_009238e4 + 0x4868) =
                       *(undefined4 *)(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x2c),
                 *(int *)(DAT_009238e4 + 0x3cbe0) != 0)) {
                FUN_00620f10(*(int *)(DAT_009238e4 + 0x3cbe0) + 0x18);
              }
            }
          }
          break;
        }
        iVar2 = iVar2 + 1;
      }
    }
  }
  if (*(int *)(DAT_009238e4 + 4) != 0) {
    FUN_00624220(*(undefined4 *)(DAT_009238e4 + 4));
    *(undefined4 *)(DAT_009238e4 + 4) = 0;
  }
  return;
}

