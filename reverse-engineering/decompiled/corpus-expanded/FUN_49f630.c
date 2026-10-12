/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49f630; label: FUN_0049f630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049f630(float *param_1,float *param_2,float *param_3,undefined4 param_4,float param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float10 fVar5;
  float local_24;
  float local_20;
  float local_1c;
  float local_18 [3];
  undefined1 local_c [12];
  
  local_24 = *param_3;
  local_20 = param_3[1];
  local_1c = param_3[2];
  iVar4 = 3;
  do {
    local_18[0] = *param_2;
    local_18[1] = 0.0;
    local_18[2] = param_2[2];
    FUN_005b3800(local_c,&local_24,local_18);
    fVar5 = (float10)FUN_005bec80(local_c);
    FUN_005b3860(&local_24,param_3,param_4,(float)(fVar5 / (float10)param_5));
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  fVar5 = (float10)FUN_005bed80(&local_24,param_2,0);
  fVar1 = local_20 - param_2[1];
  fVar2 = (float)fVar5 / param_5 + _DAT_00925018;
  uVar3 = FUN_005be2d0(local_24 - *param_2,local_1c - param_2[2]);
  *param_1 = param_5 * (float)(&DAT_029899a0)[(uVar3 & 0xffff) >> 1];
  param_1[1] = fVar1 / fVar2 - param_6 * 0.5 * ((float)fVar5 / param_5);
  param_1[2] = param_5 * (float)(&DAT_029899a0)[(int)((uVar3 & 0xffff) + 0x4000) >> 1 & 0x7fff];
  return;
}

