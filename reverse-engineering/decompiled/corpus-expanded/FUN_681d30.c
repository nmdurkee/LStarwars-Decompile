/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x681d30; label: FUN_00681d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined * FUN_00681d30(int param_1)

{
  param_1 = -param_1;
  if (6 < param_1) {
    param_1 = 0;
  }
  return (&PTR_s_ERR_UNKNOWN_00810b58)[param_1];
}

