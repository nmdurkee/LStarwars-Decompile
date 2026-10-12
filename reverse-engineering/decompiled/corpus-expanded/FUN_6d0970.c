/* Ghidra pseudocode, not original source.
 * ev_2fc6966d7cb88e652aff05d91af92c1aae7a14fbd03261d64dee7cfe7594468f
 * Entry: 0x6d0970; label: FUN_006d0970
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d0970(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_84 [128];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)local_84;
  puVar1 = (undefined4 *)FUN_00633440(0x14,1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_0076f8ec;
    puVar1[4] = 0;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    if (param_2[3] == DAT_02973ac4) {
      (**(code **)(*param_2 + 4))(param_3,DAT_02973ac4,local_84,0x80);
    }
    uVar2 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cf8e0,FUN_006bda10,FUN_006bdb50,1,param_2[4],
                         local_84);
    puVar1[1] = uVar2;
    FUN_00618e10(param_1,uVar2);
  }
  __security_check_cookie(local_4 ^ (uint)local_84);
  return;
}

