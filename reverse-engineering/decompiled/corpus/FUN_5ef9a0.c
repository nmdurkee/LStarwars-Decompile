/* Ghidra analysis pseudocode, not original source.
 * ev_87e0baa87b87192bf5be0b8e2e04b5bd4a3d9fde71e449b8cd1bb1bc961d5da7
 * Entry: 0x5ef9a0; label: FUN_005ef9a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ef9a0(float param_1,float param_2)

{
  float fVar1;
  float local_8;
  
  if (((float)DAT_00973904 == 0.0) || ((float)DAT_0080e698 == 0.0)) {
    local_8 = 0.0;
  }
  else {
    local_8 = (float)DAT_00973904 / (float)DAT_0080e698;
  }
  fVar1 = param_2 * 0.0625 - ((float)_DAT_00802030 - (float)(DAT_00973904 >> 1));
  if ((fVar1 == 0.0) || (local_8 == 0.0)) {
    local_8 = 0.0;
  }
  else {
    local_8 = fVar1 / local_8;
  }
  if (((float)DAT_00973900 == 0.0) || ((float)DAT_0080e694 == 0.0)) {
    param_2 = 0.0;
  }
  else {
    param_2 = (float)DAT_00973900 / (float)DAT_0080e694;
  }
  fVar1 = param_1 * 0.0625 - ((float)_DAT_0080202c - (float)(DAT_00973900 >> 1));
  if ((fVar1 == 0.0) || (param_2 == 0.0)) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = fVar1 / param_2;
  }
  FUN_005dac70(fVar1,local_8);
  return;
}

