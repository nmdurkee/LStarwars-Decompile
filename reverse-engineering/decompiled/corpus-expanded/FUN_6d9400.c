/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9400; label: FUN_006d9400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d9400(int param_1,byte param_2)

{
  *(byte *)(param_1 * 0x17c + DAT_02975144 + 0x4e51) = ~-(3 < param_1 - 10U) & param_2;
  return;
}

