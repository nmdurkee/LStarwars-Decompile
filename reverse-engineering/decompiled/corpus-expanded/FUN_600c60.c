/* Ghidra pseudocode, not original source.
 * ev_64f3679a1f1e131a29792e896f5cd05cb4870e5bb22e267d9bfafa2e72f365ab
 * Entry: 0x600c60; label: FUN_00600c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00600c60(int param_1)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x110) == 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x1c)) {
      iVar3 = 0;
      do {
        puVar1 = (uint *)(*(int *)(param_1 + 0x20) + 0x44 + iVar3);
        *puVar1 = *puVar1 | 4;
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x50;
      } while (iVar2 < *(int *)(param_1 + 0x1c));
    }
    return;
  }
  _memset(&DAT_0280a2f0,0xff,0x271);
  return;
}

