/* Ghidra pseudocode, not original source.
 * ev_de7bd3aa239ec0c059aa1bbec058a25d35da9446e5dffd1cda86600a1f15d21b
 * Entry: 0x658780; label: FUN_00658780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00658780(int param_1,float *param_2,float *param_3,float *param_4,float *param_5,float *param_6,
            float *param_7,undefined4 *param_8)

{
  int iVar1;
  float fVar2;
  int iVar3;
  float local_c;
  float local_8;
  float local_4;
  
  iVar3 = param_1 * 0x330 + DAT_029620a4;
  iVar1 = *(int *)(DAT_0296209c + *(short *)(param_1 * 0x330 + 0x182 + DAT_029620a4) * 4);
  if (iVar1 == 0) {
    return 0;
  }
  *param_2 = *(float *)(iVar3 + 400);
  param_2[1] = *(float *)(iVar3 + 0x194);
  param_2[2] = *(float *)(iVar3 + 0x198);
  if (*(char *)(iVar1 + 0x2c) != '\b') {
    param_3[2] = 0.0;
    param_3[1] = 0.0;
    *param_3 = 0.0;
    *param_6 = *param_3;
    param_6[1] = param_3[1];
    param_6[2] = param_3[2];
    *param_8 = 0;
    *param_7 = 0.0;
    *param_5 = 0.0;
    *param_4 = 0.0;
    return 0;
  }
  local_c = 0.0;
  local_8 = 1.0;
  local_4 = 0.0;
  FUN_005b30a0(&local_c,&local_c,iVar3 + 0x80);
  *param_6 = local_c;
  param_6[1] = local_8;
  param_6[2] = local_4;
  *param_8 = *(undefined4 *)(iVar1 + 0x48);
  fVar2 = *(float *)(iVar1 + 0x48) * *(float *)(iVar1 + 0xa4);
  *param_7 = fVar2;
  *param_3 = fVar2 * *param_6 + *param_2;
  param_3[1] = param_6[1] * *param_7 + param_2[1];
  param_3[2] = *param_7 * param_6[2] + param_2[2];
  fVar2 = (*(float *)(iVar1 + 0x60) + *(float *)(iVar1 + 0x58)) * 0.5;
  *param_4 = fVar2;
  *param_5 = ((*(float *)(iVar1 + 0x54) + *(float *)(iVar1 + 0x4c)) / 2.8) *
             *(float *)(iVar1 + 0xa4) + fVar2;
  return 1;
}

