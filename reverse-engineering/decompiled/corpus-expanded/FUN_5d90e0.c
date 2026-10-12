/* Ghidra pseudocode, not original source.
 * ev_bd8f422ab2bc288e381e81a075ad63116995ee03e48e3608bccd82f55c6aad54
 * Entry: 0x5d90e0; label: FUN_005d90e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d90e0(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (*(int *)(param_1 + 0x6c) != 0) {
    iVar3 = 0;
    do {
      puVar1 = (uint *)(*(int *)(param_1 + 0x70) + 0x1c + iVar3);
      *puVar1 = *puVar1 | 2;
      iVar2 = *(int *)(param_1 + 0x70);
      if (*(int *)(iVar2 + 0x1c + iVar3) == 0) {
        *(undefined4 *)(iVar2 + 0x1c + iVar3) = 0;
      }
      else {
        puVar1 = (uint *)(iVar2 + 0x1c + iVar3);
        *puVar1 = *puVar1 | 1;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x20;
    } while (uVar4 < *(uint *)(param_1 + 0x6c));
  }
  return;
}

