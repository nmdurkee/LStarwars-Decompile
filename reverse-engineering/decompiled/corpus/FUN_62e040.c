/* Ghidra analysis pseudocode, not original source.
 * ev_c9b97142cd7201cbac3c7782d44a236cba63ddce43dd201cca5febda4b31625e
 * Entry: 0x62e040; label: FUN_0062e040
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0062e040(float param_1,int param_2,float param_3,float param_4,int param_5)

{
  float fVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  float10 fVar5;
  
  if (((int)param_1 < 0) || (*DAT_029130e4 <= (int)param_1)) {
    return (float10)0;
  }
  if (((-1 < param_2) && (param_2 < DAT_029130e4[2])) &&
     (sVar2 = *(short *)(DAT_029130e4[7] + (int)param_1 * 2), sVar2 != -1)) {
    iVar4 = sVar2 * 0x54 + DAT_029130e4[6];
    iVar3 = *(int *)(iVar4 + 0xc);
    if (*(int *)(iVar3 + param_2 * 4) != 0) {
      fVar5 = (float10)FUN_005ca470(*(undefined4 *)(iVar3 + param_2 * 4));
      fVar1 = (float)fVar5;
      if ((param_3 < 1.0) || (fVar1 <= param_3)) {
        if ((param_4 < 1.0) || ((fVar1 <= param_4 || (param_4 <= param_3)))) {
          param_4 = fVar1 - 1.0;
        }
        else {
          param_4 = param_4 - 1.0;
        }
      }
      else if ((param_4 < 1.0) || (fVar1 <= param_4)) {
        param_4 = fVar1 - param_3;
      }
      else if (param_4 <= param_3) {
        param_4 = fVar1 - param_3;
      }
      else {
        param_4 = param_4 - param_3;
      }
      iVar3 = *(int *)(*(int *)(iVar4 + 8) + param_2 * 4);
      param_1 = (1.0 / (*(float *)(iVar3 + 0x18) / 30.0)) * 0.033333335 * param_4;
      _DAT_029a99a4 = *(float *)(iVar3 + 0x14);
      if (param_5 != 0) {
        param_1 = param_1 - _DAT_029a99a4;
      }
      return (float10)param_1;
    }
    return (float10)0;
  }
  return (float10)0;
}

