/* Ghidra analysis pseudocode, not original source.
 * ev_71178cf3925632dc66038aa0c9d310f478862b67bc1b7eebd17222539cc75c17
 * Entry: 0x5b9bf0; label: FUN_005b9bf0
 */

uint FUN_005b9bf0(float *param_1,float *param_2,float *param_3)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*param_2 < *param_1 == (*param_2 == *param_1)) {
    if (*param_1 <= *param_3) {
      uVar1 = 8;
    }
  }
  else {
    uVar1 = 1;
  }
  if (param_2[1] < param_1[1] == (param_2[1] == param_1[1])) {
    if (param_1[1] <= param_3[1]) {
      uVar1 = uVar1 | 0x10;
    }
  }
  else {
    uVar1 = uVar1 | 2;
  }
  if (param_2[2] < param_1[2] != (param_2[2] == param_1[2])) {
    return uVar1 | 4;
  }
  if (param_1[2] <= param_3[2]) {
    uVar1 = uVar1 | 0x20;
  }
  return uVar1;
}

