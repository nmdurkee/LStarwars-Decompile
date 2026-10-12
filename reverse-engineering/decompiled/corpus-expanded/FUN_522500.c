/* Ghidra pseudocode, not original source.
 * ev_1b4e61f1467db5c8e431c69a2548c20deac6709d01307c3b7894b5c0724271ef
 * Entry: 0x522500; label: FUN_00522500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00522500(undefined4 *param_1,float param_2,undefined4 param_3,undefined4 param_4)

{
  float local_6c [4];
  float local_5c;
  undefined4 local_58;
  float local_54 [3];
  undefined4 local_48;
  float local_44;
  undefined4 local_40;
  undefined4 local_30;
  undefined4 local_24;
  float local_20;
  undefined4 local_1c;
  undefined4 local_c;
  
  local_30 = param_4;
  local_c = param_4;
  local_6c[3] = (float)*param_1;
  local_58 = param_1[2];
  local_5c = _DAT_00801cc8 + (float)param_1[1];
  local_6c[0] = param_2;
  local_6c[1] = 0.0;
  local_6c[2] = 0.0;
  FUN_005b3620(local_6c,local_6c,param_3);
  FUN_005b37d0(&local_48,local_6c + 3,local_6c);
  FUN_005b3800(&local_24,local_6c + 3,local_6c);
  FUN_00512b00(&local_48,0,0);
  local_48 = local_6c[3];
  local_44 = local_5c - param_2;
  local_40 = local_58;
  local_24 = local_6c[3];
  local_20 = param_2 + local_5c;
  local_1c = local_58;
  FUN_00512b00(&local_48,0,0);
  local_6c[0] = 0.0;
  local_6c[1] = 0.0;
  local_6c[2] = param_2;
  FUN_005b3620(local_6c,local_6c,param_3);
  FUN_005b37d0(&local_48,local_6c + 3,local_6c);
  FUN_005b3800(&local_24,local_6c + 3,local_6c);
  FUN_00512b00(&local_48,0,0);
  local_54[0] = -local_6c[2] * 0.2;
  local_54[1] = 0.0;
  local_54[2] = local_6c[0] * 0.2;
  FUN_005b37d0(&local_24,local_6c + 3,local_54);
  FUN_00512b00(&local_48,0,0);
  FUN_005b3800(&local_24,local_6c + 3,local_54);
  FUN_00512b00(&local_48,0,0);
  return;
}

