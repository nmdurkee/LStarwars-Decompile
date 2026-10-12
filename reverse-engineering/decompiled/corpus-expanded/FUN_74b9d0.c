/* Ghidra pseudocode, not original source.
 * ev_d88267bcb152659f8a516596ec9fcf93efabf83ae0338dc3d490a153d971aac8
 * Entry: 0x74b9d0; label: FUN_0074b9d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074b9d0(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *param_1 = *param_3;
    param_1 = param_1 + 1;
  }
  return;
}

