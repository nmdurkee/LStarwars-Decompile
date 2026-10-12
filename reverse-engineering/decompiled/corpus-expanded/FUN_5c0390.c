/* Ghidra pseudocode, not original source.
 * ev_36c2cdffab22dec35ae5154a8d67af88b00f5702395280041def6b77535d68b9
 * Entry: 0x5c0390; label: thunk_FUN_005b5700
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void thunk_FUN_005b5700(float *param_1,float *param_2,float *param_3)

{
  int iVar1;
  float *pfVar2;
  float afStack_40 [5];
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((param_1 != param_2) && (param_1 != param_3)) {
    *param_1 = param_3[8] * param_2[2] + *param_2 * *param_3 + param_2[1] * param_3[4];
    param_1[1] = param_3[9] * param_2[2] + *param_2 * param_3[1] + param_2[1] * param_3[5];
    param_1[2] = param_3[10] * param_2[2] + param_2[1] * param_3[6] + param_3[2] * *param_2;
    param_1[3] = 0.0;
    param_1[4] = param_2[6] * param_3[8] + *param_3 * param_2[4] + param_2[5] * param_3[4];
    param_1[5] = param_2[6] * param_3[9] + param_2[4] * param_3[1] + param_2[5] * param_3[5];
    param_1[6] = param_2[6] * param_3[10] + param_2[5] * param_3[6] + param_3[2] * param_2[4];
    param_1[7] = 0.0;
    param_1[8] = param_2[10] * param_3[8] + param_2[8] * *param_3 + param_3[4] * param_2[9];
    param_1[9] = param_3[9] * param_2[10] + param_3[5] * param_2[9] + param_2[8] * param_3[1];
    param_1[10] = param_2[10] * param_3[10] + param_2[8] * param_3[2] + param_2[9] * param_3[6];
    param_1[0xb] = 0.0;
    param_1[0xe] = 0.0;
    param_1[0xd] = 0.0;
    param_1[0xc] = 0.0;
    param_1[0xf] = 1.0;
    return;
  }
  afStack_40[0] = param_3[8] * param_2[2] + *param_2 * *param_3 + param_2[1] * param_3[4];
  afStack_40[1] = param_3[9] * param_2[2] + *param_2 * param_3[1] + param_2[1] * param_3[5];
  afStack_40[2] = param_3[10] * param_2[2] + param_2[1] * param_3[6] + param_3[2] * *param_2;
  afStack_40[3] = 0.0;
  afStack_40[4] = param_2[6] * param_3[8] + *param_3 * param_2[4] + param_2[5] * param_3[4];
  fStack_2c = param_2[6] * param_3[9] + param_2[4] * param_3[1] + param_2[5] * param_3[5];
  fStack_28 = param_2[6] * param_3[10] + param_2[5] * param_3[6] + param_3[2] * param_2[4];
  uStack_24 = 0;
  fStack_20 = param_2[10] * param_3[8] + param_2[8] * *param_3 + param_3[4] * param_2[9];
  fStack_1c = param_3[9] * param_2[10] + param_3[5] * param_2[9] + param_2[8] * param_3[1];
  fStack_18 = param_2[10] * param_3[10] + param_2[8] * param_3[2] + param_2[9] * param_3[6];
  uStack_14 = 0;
  uStack_8 = 0;
  uStack_c = 0;
  uStack_10 = 0;
  uStack_4 = 0x3f800000;
  pfVar2 = afStack_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}

