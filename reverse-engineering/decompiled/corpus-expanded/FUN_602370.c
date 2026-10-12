/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x602370; label: FUN_00602370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00602370(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    do {
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + iVar2 * 4) + 0x24) =
           *(undefined4 *)(DAT_00986e9c + iVar2 * 4);
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + iVar2 * 4) + 0x1c) = 0;
      iVar1 = iVar2 * 4;
      iVar2 = iVar2 + 1;
      *(undefined4 *)(*(int *)(*(int *)(param_1 + 8) + iVar1) + 0x20) = 0;
    } while (iVar2 != *(int *)(param_1 + 4));
  }
  return;
}

