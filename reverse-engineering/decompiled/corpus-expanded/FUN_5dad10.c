/* Ghidra pseudocode, not original source.
 * ev_64ab134b4afd9c8d0a163dd8f67d256d98012891aab565beeb69ac94b847fa54
 * Entry: 0x5dad10; label: FUN_005dad10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

