/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e2e0; label: FUN_0056e2e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e2e0(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_DAT_008032c4;
  iVar3 = 0;
  if (0 < *(int *)(PTR_DAT_008032c4 + 4)) {
    iVar2 = 0;
    do {
      if ((param_1 == 0) || ((*(uint *)(iVar2 + 0x1c + *(int *)puVar1) & 0x200000) != 0)) {
        *(undefined1 *)(iVar2 + 8 + *(int *)puVar1) = 0;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x20;
    } while (iVar3 < *(int *)(puVar1 + 4));
  }
  FUN_0056e080();
  return;
}

