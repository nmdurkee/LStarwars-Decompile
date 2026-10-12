/* Ghidra analysis pseudocode, not original source.
 * ev_5937183d084659f3cd2a7a2e71fd5c7a233dbdbc790437ca60456b8bfcc76022
 * Entry: 0x548fe0; label: FUN_00548fe0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548fe0(float *param_1)

{
  float fVar1;
  
  param_1[1] = *param_1;
  *param_1 = *param_1 + _DAT_00925018;
  fVar1 = _DAT_00925018 + param_1[2];
  param_1[2] = fVar1;
  if (!NAN(fVar1) && 1.0 < fVar1 != (fVar1 == 1.0)) {
    do {
      param_1[2] = param_1[2] - 1.0;
    } while (1.0 < param_1[2] != (param_1[2] == 1.0));
  }
  if (param_1[3] != -NAN) {
    param_1[3] = (float)((int)param_1[3] + 1);
  }
  return;
}

