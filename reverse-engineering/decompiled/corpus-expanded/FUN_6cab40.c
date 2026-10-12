/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cab40; label: FUN_006cab40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cab40(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 auStack_b4 [4];
  float local_b0;
  float fStack_ac;
  float fStack_a8;
  undefined1 auStack_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_b4;
  puVar1 = (undefined4 *)FUN_00633440(0x1c,1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_0076f800;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,DAT_02973ab8,&local_b0,0);
    uVar2 = FUN_006267f0(puVar1,&DAT_0081f9a0,FUN_006caac0,param_2[4]);
    puVar1[1] = uVar2;
    FUN_00618e10(param_1,uVar2);
    FUN_004f2740(auStack_98,&DAT_0076bd70,(double)local_b0);
    iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006caac0,FUN_006b98a0,FUN_006c3b00,2,&DAT_0076fe44
                         ,auStack_98);
    puVar1[4] = iVar3;
    *(undefined1 *)(iVar3 + 0x10) = 1;
    FUN_0061ee00(puVar1[1],puVar1[4]);
    FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_ac);
    iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006caac0,FUN_006b98a0,FUN_006c3b00,2,&DAT_0076fe40
                         ,auStack_98);
    puVar1[5] = iVar3;
    *(undefined1 *)(iVar3 + 0x10) = 2;
    FUN_0061ee00(puVar1[1],puVar1[5]);
    FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_a8);
    iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006caac0,FUN_006b98a0,FUN_006c3b00,2,&DAT_0076fe3c
                         ,auStack_98);
    puVar1[6] = iVar3;
    *(undefined1 *)(iVar3 + 0x10) = 3;
    FUN_0061ee00(puVar1[1],puVar1[6]);
  }
  __security_check_cookie(local_14 ^ (uint)auStack_b4);
  return;
}

