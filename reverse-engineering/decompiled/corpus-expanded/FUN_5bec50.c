/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bec50; label: FUN_005bec50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005bec50(int param_1)

{
  byte bVar1;
  
  bVar1 = 0;
  if (1 < param_1) {
    do {
      bVar1 = bVar1 + 1;
    } while (1 << (bVar1 & 0x1f) < param_1);
  }
  return;
}

