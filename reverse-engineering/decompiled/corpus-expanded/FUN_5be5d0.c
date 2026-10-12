/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be5d0; label: FUN_005be5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005be5d0(int param_1)

{
  int iVar1;
  
  for (iVar1 = ((param_1 < 0x80) - 1 & 0x7f) + 1; iVar1 < param_1; iVar1 = iVar1 * 2) {
  }
  return;
}

