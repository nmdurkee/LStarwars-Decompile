/* Ghidra analysis pseudocode, not original source.
 * ev_7ed3362792c3ecc1c7f2b3fdd5b033605c88aa142786b47e04128bf45777c493
 * Entry: 0x6bacb0; label: FUN_006bacb0
 */

void FUN_006bacb0(undefined4 param_1,float param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_50;
  undefined4 local_4c;
  float local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  float local_38;
  undefined4 local_34;
  float local_30 [5];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_48 = -param_2;
  puVar1 = &local_50;
  iVar2 = 4;
  local_50 = 0;
  local_4c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_34 = 0;
  local_38 = param_2;
  local_30[0] = param_2 * 0.5;
  local_30[1] = 0.0;
  local_30[2] = 0.0;
  local_30[3] = 0.0;
  local_30[4] = local_48 * 0.5;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  do {
    FUN_005b30a0(puVar1,puVar1,param_1);
    puVar1 = puVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_006ba7d0(&local_50,&local_40,param_3);
  FUN_006ba7d0(&local_40,local_30,param_3);
  FUN_006ba7d0(&local_40,local_30 + 4,param_3);
  FUN_006ba7d0(local_30,local_30 + 4,param_3);
  return;
}

