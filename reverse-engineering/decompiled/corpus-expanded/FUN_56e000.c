/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e000; label: FUN_0056e000
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e000(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = PTR_DAT_008032c4;
  *(int **)PTR_DAT_008032c4 = param_1;
  *(undefined4 *)(puVar3 + 4) = 0;
  if (param_1 != (int *)0x0) {
    iVar2 = *param_1;
    while (iVar2 != 0) {
      piVar1 = (int *)(puVar3 + 4);
      *piVar1 = *piVar1 + 1;
      param_1 = param_1 + 8;
      iVar2 = *param_1;
    }
  }
  return;
}

