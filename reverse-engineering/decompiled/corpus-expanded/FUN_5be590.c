/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be590; label: FUN_005be590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005be590(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + param_1 & 0xffff;
  if (0x7fff < uVar1) {
    uVar1 = uVar1 - 0x10000;
  }
  return uVar1;
}

