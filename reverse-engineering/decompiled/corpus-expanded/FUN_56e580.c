/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56e580; label: FUN_0056e580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056e580(int param_1,int param_2)

{
  if ((((-1 < param_1) && (param_1 < *(int *)(PTR_DAT_008032c4 + 4))) && (-1 < param_2)) &&
     (param_2 < DAT_00951360)) {
    *(char *)(param_1 * 0x20 + 0xb + *(int *)PTR_DAT_008032c4) = (char)param_2;
  }
  return;
}

