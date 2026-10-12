/* Ghidra analysis pseudocode, not original source.
 * ev_310631bb624827f7a98d5acd3a21e7258cb6e2cd16a2b6553760fed88e2e9667
 * Entry: 0x428a40; label: FUN_00428a40
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00428a40(int *param_1)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  
  if ((((param_1 != (int *)0x0) && (iVar3 = FUN_0056e160(0x2c), iVar3 != 0)) && (DAT_00951154 == 0))
     && (DAT_0093b338 == 0)) {
    if ((1.0 <= (float)param_1[1]) || ((float)param_1[1] <= 1.0 - _DAT_007f5db4)) {
      bVar2 = false;
      if (((float)param_1[1] <= 0.0) || (_DAT_007f5db4 + 0.0 <= (float)param_1[1]))
      goto LAB_00428b16;
    }
    else {
      bVar2 = true;
    }
    fVar1 = (float)param_1[2] + _DAT_00925018;
    param_1[2] = (int)fVar1;
    if (_DAT_007f5db0 < fVar1 != (_DAT_007f5db0 == fVar1)) {
      param_1[1] = 0x3f000000;
      if (!bVar2) {
        *param_1 = *param_1 + -1;
        param_1[2] = 0;
        return (float10)(float)param_1[1];
      }
      *param_1 = *param_1 + 1;
      param_1[2] = 0;
      return (float10)(float)param_1[1];
    }
  }
LAB_00428b16:
  return (float10)(float)param_1[1];
}

