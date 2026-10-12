/* Ghidra analysis pseudocode, not original source.
 * ev_177857cb78ddb8ad13dc6718881af1dfaef05e8a3811f551bff9ab7ba98e27a8
 * Entry: 0x545030; label: FUN_00545030
 */

void FUN_00545030(undefined4 param_1,float *param_2,int param_3)

{
  float *pfVar1;
  int iVar2;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = 0;
  pfVar1 = param_2;
  if (0 < param_3) {
    do {
      if (iVar2 != param_3 + -1) {
        local_c = pfVar1[3] - *param_2;
        local_8 = pfVar1[4] - param_2[1];
        local_4 = pfVar1[5] - param_2[2];
        FUN_005b3b30(&local_c,&local_c);
        local_34 = local_4;
        local_38 = local_c;
        local_3c = local_8;
        if (local_4 != local_c) {
          local_34 = local_c;
          local_38 = local_8;
          local_3c = local_4;
        }
        local_3c = -local_3c;
        FUN_005b3920(&local_30,&local_c,&local_3c);
        FUN_005b3b30(&local_30,&local_30);
        local_24 = (local_30 - local_3c) * 0.5 + local_3c;
        local_20 = (local_2c - local_38) * 0.5 + local_38;
        local_1c = local_34 + (local_28 - local_34) * 0.5;
        FUN_005b3b30(&local_24,&local_24);
        local_18 = (-local_3c - local_30) * 0.5 + local_30;
        local_14 = (-local_38 - local_2c) * 0.5 + local_2c;
        local_10 = local_28 + (-local_34 - local_28) * 0.5;
        FUN_005b3b30(&local_18,&local_18);
        local_3c = local_3c * 0.08;
        local_38 = local_38 * 0.08;
        local_34 = local_34 * 0.08;
        local_30 = local_30 * 0.08;
        local_2c = local_2c * 0.08;
        local_28 = local_28 * 0.08;
        local_24 = local_24 * 0.08;
        local_20 = local_20 * 0.08;
        local_1c = local_1c * 0.08;
        local_18 = local_18 * 0.08;
        local_14 = local_14 * 0.08;
        local_10 = local_10 * 0.08;
      }
      iVar2 = iVar2 + 1;
      param_2 = param_2 + 3;
      pfVar1 = pfVar1 + 3;
    } while (iVar2 < param_3);
  }
  return;
}

