/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5bde90; label: FUN_005bde90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005bde90(int param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return (-1 < param_2) - 1 & 0x8000;
  }
  if (param_2 == 0) {
    return ((-1 < param_1) - 1 & 0x8000) + 0x4000;
  }
  if (-1 < param_1) {
    if (param_2 < 0) {
      uVar1 = FUN_005bde60();
      return 0x8000 - (uVar1 & 0xffff);
    }
    uVar1 = FUN_005bde60();
    return uVar1 & 0xffff;
  }
  if (param_2 < 0) {
    uVar1 = FUN_005bde60();
    return (uVar1 & 0xffff) + 0x8000;
  }
  uVar1 = FUN_005bde60();
  return -(uVar1 & 0xffff);
}

