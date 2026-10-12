/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be600; label: FUN_005be600
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005be600(int *param_1,int *param_2,int *param_3,int param_4,int param_5,int param_6)

{
  *param_1 = param_4 + 0x8000;
  *param_2 = -0x8000 - param_5;
  *param_3 = param_6 + 0x8000;
  return;
}

