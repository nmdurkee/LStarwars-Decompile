/* Ghidra analysis pseudocode, not original source.
 * ev_0c8ba0b3b7b14392dbbecf96693a80f9f750c2c118e50ed36c877e83d8a87913
 * Entry: 0x5eda90; label: FUN_005eda90
 */

void FUN_005eda90(undefined4 *param_1,undefined4 *param_2)

{
  float fVar1;
  float10 fVar2;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  local_24 = 0.0;
  local_20 = 1.0;
  local_1c = 0.0;
  FUN_005b6ec0(&DAT_009736e8,local_c);
  FUN_005b3800(&local_3c,local_c,param_2);
  FUN_005b3b30(&local_3c,&local_3c);
  fVar2 = (float10)FUN_005b39e0(&local_24,&local_3c);
  fVar1 = (float)fVar2;
  local_30 = local_24 - fVar1 * local_3c;
  local_2c = local_20 - local_38 * fVar1;
  local_28 = local_1c - local_34 * fVar1;
  FUN_005b3b30(&local_30,&local_30);
  FUN_005b3920(&local_18,&local_30,&local_3c);
  *param_1 = local_18;
  param_1[4] = local_30;
  param_1[8] = local_3c;
  param_1[1] = local_14;
  param_1[5] = local_2c;
  param_1[9] = local_38;
  param_1[2] = local_10;
  param_1[6] = local_28;
  param_1[10] = local_34;
  param_1[0xb] = 0;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[0xf] = 0x3f800000;
  param_1[0xc] = *param_2;
  param_1[0xd] = param_2[1];
  param_1[0xe] = param_2[2];
  return;
}

