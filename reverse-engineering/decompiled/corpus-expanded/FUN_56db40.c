/* Ghidra pseudocode, not original source.
 * ev_55c3fafd2bb47b4484afc45519bee328d1122611dc21b8ef391b43f817c8682b
 * Entry: 0x56db40; label: FUN_0056db40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0056db40(int param_1)

{
  if (((DAT_00802814 == -1) || (*(char *)(param_1 + 0x7b5) != DAT_00802814)) &&
     ((DAT_00802818 == -1 ||
      ((*(char *)(param_1 + 0x7b5) != DAT_00802818 || (*(int *)(param_1 + 0x798) == 0)))))) {
    return 0;
  }
  return 1;
}

