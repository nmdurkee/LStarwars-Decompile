/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5abf00; label: FUN_005abf00
 */

void FUN_005abf00(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 *param_7,int param_8)

{
  float fVar1;
  float10 fVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0xbf800000;
  FUN_005b3200(&local_30,&local_30,param_2);
  FUN_00550250(param_1,param_3,param_4,param_5,&local_18,&local_c);
  fVar2 = (float10)FUN_005b3c50(&local_18,param_1,&local_24);
  fVar2 = (float10)FUN_005c0240((float)fVar2);
  if ((float)fVar2 <= 0.0) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = 1.0 / (float)fVar2;
  }
  local_24 = fVar1 * local_24;
  local_20 = local_20 * fVar1;
  local_1c = fVar1 * local_1c;
  fVar2 = (float10)FUN_005b39e0(&local_24,&local_30);
  if (((float)(&DAT_029899a0)[DAT_00805e2c + 0x4000 >> 1 & 0x7fff] < (float)fVar2) || (param_8 == 0)
     ) {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_18;
      param_6[1] = local_14;
      param_6[2] = local_10;
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = local_c;
      param_7[1] = local_8;
      param_7[2] = local_4;
    }
  }
  else {
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_30;
      param_6[1] = local_2c;
      param_6[2] = local_28;
    }
    if (param_7 != (undefined4 *)0x0) {
      *param_7 = *param_1;
      param_7[1] = param_1[1];
      param_7[2] = param_1[2];
      return;
    }
  }
  return;
}

