/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9510; label: FUN_006d9510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d9510(int param_1,int param_2)

{
  if ((9 < param_1) && (param_1 < 0xe)) {
    if (param_2 != *(int *)(DAT_02975144 + 0x6608)) {
      param_1 = param_1 + 1;
    }
    if (-1 < param_2) {
      param_1 = param_1 + param_2 * 2;
    }
  }
  return param_1;
}

