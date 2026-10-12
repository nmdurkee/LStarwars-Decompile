/* Ghidra analysis pseudocode, not original source.
 * ev_93d7dcfdde9a808337523cfea9e371187d945893e914ed56ca2b2926a7aff66e
 * Entry: 0x62a9a0; label: FUN_0062a9a0
 */

int FUN_0062a9a0(undefined4 *param_1,float *param_2,undefined4 param_3,undefined4 param_4,
                float param_5,float param_6)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 local_24 [12];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  if (param_6 <= 0.0) {
    iVar2 = FUN_0067b280(param_1,param_2,param_3,param_4);
    return iVar2;
  }
  fVar1 = param_2[2] * param_2[2] + *param_2 * *param_2 + param_2[1] * param_2[1];
  if (param_5 * param_5 < fVar1) {
    return 0;
  }
  if (fVar1 < param_6 * param_6) {
    iVar2 = FUN_0067b280(param_1,param_2,param_3,param_4);
    return iVar2;
  }
  fVar3 = (float10)FUN_005c0240(fVar1);
  fVar1 = (float)fVar3;
  fVar3 = (float10)FUN_0062a620(0x3f800000,fVar1);
  FUN_005b3830(local_c,param_2,(float)fVar3);
  local_18 = 0;
  local_30 = *param_1;
  local_14 = 0;
  local_2c = param_1[1];
  local_10 = 0;
  local_28 = param_1[2];
  while( true ) {
    if (fVar1 <= 0.0) {
      return 0;
    }
    if (param_6 < fVar1 == (param_6 == fVar1)) {
      FUN_005b3830(local_24,local_c,fVar1);
      fVar1 = 0.0;
    }
    else {
      FUN_005b3830(local_24,local_c,param_6);
      fVar1 = fVar1 - param_6;
    }
    iVar2 = FUN_0067b280(&local_30,local_24,param_3,param_4);
    if (iVar2 != 0) break;
    FUN_005b37d0(&local_30,&local_30,local_24);
    FUN_005b37d0(&local_18,&local_18,local_24);
  }
  FUN_005b37d0(param_2,&local_18,local_24);
  return iVar2;
}

