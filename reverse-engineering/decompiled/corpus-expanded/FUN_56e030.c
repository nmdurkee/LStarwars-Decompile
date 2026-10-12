/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e030; label: FUN_0056e030
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056e030(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *(int *)(PTR_DAT_008032c4 + 4)) {
    iVar3 = 0;
    do {
      iVar1 = FUN_004f8b10(*(undefined4 *)(iVar3 + *(int *)PTR_DAT_008032c4),param_1);
      if (iVar1 == 0) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
    } while (iVar2 < *(int *)(PTR_DAT_008032c4 + 4));
  }
  return -1;
}

