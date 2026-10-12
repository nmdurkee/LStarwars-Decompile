/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e130; label: FUN_0056e130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e130(int param_1,int param_2)

{
  if ((-1 < param_1) && (param_1 < *(int *)(PTR_DAT_008032c4 + 4))) {
    *(bool *)(param_1 * 0x20 + 8 + *(int *)PTR_DAT_008032c4) = param_2 != 0;
    FUN_0056e080();
    return;
  }
  return;
}

