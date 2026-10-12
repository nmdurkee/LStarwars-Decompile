/* Ghidra analysis pseudocode, not original source.
 * ev_7bf4cf8279d8e200655baf4cbe0b44c1a6d004e84309270e7e1edaecfde67eb6
 * Entry: 0x5c73d0; label: FUN_005c73d0
 */

void FUN_005c73d0(undefined4 param_1,float param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_EAX;
  int in_ECX;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_c;
  float local_8;
  float local_4;
  
  local_24 = 3.4028235e+38;
  local_20 = -3.4028235e+38;
  local_18 = -3.4028235e+38;
  local_1c = 3.4028235e+38;
  if (0 < in_EAX) {
    do {
      FUN_005b37d0(&local_c,in_ECX,param_1);
      fVar1 = (param_2 * local_c) / local_4;
      fVar2 = (param_2 * local_8) / local_4;
      fVar3 = fVar1;
      if ((local_24 <= fVar1) && (fVar3 = local_24, local_20 < fVar1)) {
        local_20 = fVar1;
      }
      local_24 = fVar3;
      fVar1 = fVar2;
      if ((local_1c <= fVar2) && (fVar1 = local_1c, local_18 < fVar2)) {
        local_18 = fVar2;
      }
      local_1c = fVar1;
      in_ECX = in_ECX + 0x10;
      in_EAX = in_EAX + -1;
    } while (in_EAX != 0);
  }
  *param_3 = local_24;
  *param_4 = local_20;
  *param_5 = local_1c;
  *param_6 = local_18;
  return;
}

