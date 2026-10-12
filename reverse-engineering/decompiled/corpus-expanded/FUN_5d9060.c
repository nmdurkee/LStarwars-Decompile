/* Ghidra pseudocode, not original source.
 * ev_a2251cf45e3df493b8c06ffdfc61df01e05d9eddb60bcc7f5168d43543d79db8
 * Entry: 0x5d9060; label: FUN_005d9060
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d9060(int param_1,int param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if (*(int *)(param_1 + 0x6c) != 0) {
    iVar2 = 0;
    do {
      if (*(char *)(*(int *)(param_1 + 0x70) + 0x1a + iVar2) == param_2) {
        if (param_3 == 0) {
          *(undefined4 *)(*(int *)(param_1 + 0x70) + 0x1c + iVar2) = 0;
        }
        else {
          puVar1 = (uint *)(*(int *)(param_1 + 0x70) + 0x1c + iVar2);
          *puVar1 = *puVar1 | 1;
        }
      }
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (uVar3 < *(uint *)(param_1 + 0x6c));
  }
  return;
}

