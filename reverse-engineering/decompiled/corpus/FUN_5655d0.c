/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x5655d0; label: FUN_005655d0
 */

void FUN_005655d0(float *param_1,undefined4 *param_2)

{
  float fVar1;
  
  if (-0.85 <= *param_1) {
    if ((0.85 < *param_1) && (*param_1 = 0.85, param_2 != (undefined4 *)0x0)) {
      *param_2 = 0;
    }
  }
  else {
    *param_1 = -0.85;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
  }
  fVar1 = -0.85;
  if (((param_1[1] < -0.85) || (fVar1 = 0.85, 0.85 < param_1[1])) &&
     (param_1[1] = fVar1, param_2 != (undefined4 *)0x0)) {
    param_2[1] = 0;
    return;
  }
  return;
}

