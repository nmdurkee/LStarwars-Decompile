/* Ghidra pseudocode, not original source.
 * ev_86be5d0b29c9dd19f96c33e6e07bf1c9a03b071eda0eb4c5bb2270815bb5be61
 * Entry: 0x529f20; label: FUN_00529f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00529f20(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((param_2 != 0) && (*(int *)(DAT_009238e4 + 0x371b0) != 0)) {
    if (*(int *)(param_2 + 0xc) == -1) {
      *(undefined4 *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x84) = 0;
      return;
    }
    iVar1 = FUN_004f1440(DAT_009238e4 + 0x3cbd8);
    if (iVar1 != 0) {
      do {
        if (*(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x3c) == *(int *)(iVar1 + 0x2c)) {
          if (iVar2 == *(int *)(param_2 + 0xc)) {
            *(int *)(*(int *)(DAT_009238e4 + 0x371b0) + 0x84) = iVar1;
            return;
          }
          iVar2 = iVar2 + 1;
        }
        iVar1 = FUN_004f1460(DAT_009238e4 + 0x3cbd8,iVar1);
      } while (iVar1 != 0);
      return;
    }
  }
  return;
}

