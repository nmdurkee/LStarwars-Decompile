/* Ghidra analysis pseudocode, not original source.
 * ev_63802f60b4285c5edf6c429a3d1e3220ec0e39d2563d3bbc7dd58661d8af5682
 * Entry: 0x5be2d0; label: FUN_005be2d0
 */

uint FUN_005be2d0(float param_1,float param_2)

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
          uVar1 = FUN_005be030(-param_1,-param_2);
          return (uVar1 & 0xffff) + 0x8000;
        }
        uVar1 = FUN_005be030(-param_1,param_2);
        return -(uVar1 & 0xffff);
      }
      if (param_2 < 0.0) {
        uVar1 = FUN_005be030(param_1,-param_2);
        return 0x8000 - (uVar1 & 0xffff);
      }
      uVar1 = FUN_005be030(param_1,param_2);
      uVar1 = uVar1 & 0xffff;
    }
    return uVar1;
  }
  if (param_2 < 0.0) {
    return 0x8000;
  }
  return 0;
}

