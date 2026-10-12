/* Ghidra pseudocode, not original source.
 * ev_2c08301f859172184cf112c2b2791d688bc6316a9907cd3ed4418d6c565e9413
 * Entry: 0x5be3b0; label: FUN_005be3b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_005be3b0(float param_1,float param_2)

{
  uint uVar1;
  
  if (param_1 != 0.0) {
    if (param_2 == 0.0) {
      uVar1 = 0xc000;
      if (0.0 <= param_1) {
        return 0x4000;
      }
    }
    else {
      if (param_1 < 0.0) {
        if (param_2 < 0.0) {
          uVar1 = FUN_005be080(-param_1,-param_2);
          return (uVar1 & 0xffff) + 0x8000;
        }
        uVar1 = FUN_005be080(-param_1,param_2);
        return -(uVar1 & 0xffff);
      }
      if (param_2 < 0.0) {
        uVar1 = FUN_005be080(param_1,-param_2);
        return 0x8000 - (uVar1 & 0xffff);
      }
      uVar1 = FUN_005be080(param_1,param_2);
      uVar1 = uVar1 & 0xffff;
    }
    return uVar1;
  }
  if (param_2 < 0.0) {
    return 0x8000;
  }
  return 0;
}

