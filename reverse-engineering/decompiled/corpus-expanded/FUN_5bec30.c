/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bec30; label: FUN_005bec30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005bec30(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; 1 < param_1; param_1 = param_1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

