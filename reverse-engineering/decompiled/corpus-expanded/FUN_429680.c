/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429680; label: FUN_00429680
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00429680(int param_1,int param_2)

{
  if (((param_1 != 0) && (param_2 != 0)) &&
     ((*(short *)(param_2 + 0x1064) == DAT_007f1878 ||
      (*(short *)(param_2 + 0x1064) == DAT_007f1884)))) {
    FUN_00547930(0x4a,param_2 + 0x80,0,0);
  }
  return;
}

