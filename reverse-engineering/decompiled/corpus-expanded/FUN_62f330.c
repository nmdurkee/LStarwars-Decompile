/* Ghidra pseudocode, not original source.
 * ev_4e08cb6b9a05324ae7a2b7ff12e5cd4300e2bf96324e358c1c445da0c9e3f38b
 * Entry: 0x62f330; label: FUN_0062f330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062f330(int param_1,int param_2,float *param_3,undefined4 param_4,float *param_5,
                 undefined4 param_6,int param_7)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  
  if (*(float *)(param_2 + 8) < *(float *)(param_2 + 0x25c)) {
    *(float *)(param_2 + 0x244) = *param_3;
    *(float *)(param_2 + 0x248) = param_3[1];
    *(float *)(param_2 + 0x24c) = param_3[2];
  }
  pfVar1 = (float *)(param_2 + 0x26c);
  *pfVar1 = *param_3 - *(float *)(param_2 + 0x244);
  if (param_7 == 0) {
    fVar2 = 0.0;
  }
  else {
    fVar2 = param_3[1] - *(float *)(param_2 + 0x248);
  }
  *(float *)(param_2 + 0x270) = fVar2;
  *(float *)(param_2 + 0x274) = param_3[2] - *(float *)(param_2 + 0x24c);
  FUN_005b3200(pfVar1,pfVar1,param_2 + 0xb8);
  if (param_7 == 0) {
    *(undefined4 *)(param_2 + 0x270) = 0;
  }
  *(float *)(param_2 + 0x244) = *param_3;
  *(float *)(param_2 + 0x248) = param_3[1];
  fVar2 = param_3[2];
  *(undefined4 *)(param_2 + 0x25c) = *(undefined4 *)(param_2 + 8);
  *(float *)(param_2 + 0x24c) = fVar2;
  if (*(short *)(param_2 + 0x42) == -1) {
    *(float *)(param_1 + 0x30) = *param_5;
    if (param_7 != 0) {
      *(float *)(param_1 + 0x34) = param_5[1];
    }
    *(float *)(param_1 + 0x38) = param_5[2];
  }
  else {
    iVar3 = *(int *)(*(int *)(*(int *)(param_2 + 0x50) + 8) + *(short *)(param_2 + 0x42) * 4);
    fVar2 = *(float *)(iVar3 + 0x44);
    *(float *)(param_1 + 0x30) = *param_5 + *(float *)(iVar3 + 0x3c);
    *(float *)(param_1 + 0x38) = param_5[2] + fVar2;
    if (param_7 == 0) goto LAB_0062f485;
    *(float *)(param_1 + 0x34) =
         *(float *)(*(int *)(*(int *)(*(int *)(param_2 + 0x50) + 8) + *(short *)(param_2 + 0x42) * 4
                            ) + 0x40) + param_5[1];
  }
  if ((param_7 != 0) && (*(float *)(param_2 + 0x270) == 0.0)) {
    *(undefined4 *)(param_2 + 0x270) = 0x2d2febff;
    return;
  }
LAB_0062f485:
  if ((*pfVar1 == 0.0) && (*(float *)(param_2 + 0x274) == 0.0)) {
    *pfVar1 = 1e-11;
    return;
  }
  return;
}

