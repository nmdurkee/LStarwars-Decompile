/* Ghidra pseudocode, not original source.
 * ev_fbc0fd73cf89a7f733f4465e4ab1049333b8e7c593c45a6546f4f82b49062809
 * Entry: 0x5ed9a0; label: FUN_005ed9a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ed9a0(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  local_3c = 0;
  local_38 = 0x3f800000;
  local_34 = 0;
  FUN_005b6ec0(&DAT_009736e8,local_18);
  FUN_005b3800(local_c,local_18,param_2);
  FUN_005b3920(&local_30,&local_3c,local_c);
  FUN_005b3b30(&local_30,&local_30);
  FUN_005b3920(&local_24,&local_3c,&local_30);
  FUN_005b3b30(&local_24,&local_24);
  *param_1 = local_30;
  param_1[4] = local_3c;
  param_1[8] = local_24;
  param_1[1] = local_2c;
  param_1[5] = local_38;
  param_1[9] = local_20;
  param_1[2] = local_28;
  param_1[6] = local_34;
  param_1[10] = local_1c;
  param_1[0xb] = 0;
  param_1[7] = 0;
  param_1[3] = 0;
  param_1[0xf] = 0x3f800000;
  param_1[0xc] = *param_2;
  param_1[0xd] = param_2[1];
  param_1[0xe] = param_2[2];
  return;
}

