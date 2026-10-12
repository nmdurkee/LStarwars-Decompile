/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54dfc0; label: FUN_0054dfc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

char * FUN_0054dfc0(undefined4 param_1,int param_2)

{
  if (param_2 == 1) {
    return "Occupied";
  }
  if (param_2 != 2) {
    return "Active";
  }
  return "Occupied By 2";
}

