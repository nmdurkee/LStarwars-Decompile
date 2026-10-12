/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5dad10; label: FUN_005dad10
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dad10(float *param_1,float *param_2)

{
  float fVar1;
  float local_8;
  
  if (((float)DAT_00973900 == 0.0) || ((float)DAT_0080e694 == 0.0)) {
    local_8 = 0.0;
  }
  else {
    local_8 = (float)DAT_00973900 / (float)DAT_0080e694;
  }
  fVar1 = (float)DAT_00963e10 * 0.0625 - ((float)_DAT_0080202c - (float)(DAT_00973900 >> 1));
  if ((fVar1 == 0.0) || (local_8 == 0.0)) {
    local_8 = 0.0;
  }
  else {
    local_8 = fVar1 / local_8;
  }
  *param_1 = local_8;
  if (((float)DAT_00973904 == 0.0) || ((float)DAT_0080e698 == 0.0)) {
    param_1 = (float *)0x0;
  }
  else {
    param_1 = (float *)((float)DAT_00973904 / (float)DAT_0080e698);
  }
  fVar1 = (float)DAT_00963e14 * 0.0625 - ((float)_DAT_00802030 - (float)(DAT_00973904 >> 1));
  if ((fVar1 != 0.0) && ((float)param_1 != 0.0)) {
    *param_2 = fVar1 / (float)param_1;
    return;
  }
  *param_2 = 0.0;
  return;
}

