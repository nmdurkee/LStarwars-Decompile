/* Ghidra pseudocode, not original source.
 * ev_78df0822e84eed863df7f286a1c553c9b84caeaa7e7dd857dd35c61ca827b7f8
 * Entry: 0x6cade0; label: FUN_006cade0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006cade0(undefined4 param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  float10 fVar4;
  undefined1 auStack_f4 [8];
  float fStack_ec;
  float fStack_e8;
  float fStack_e4;
  float local_e0;
  float fStack_dc;
  float fStack_d8;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_b0;
  float fStack_ac;
  float fStack_a8;
  undefined1 auStack_98 [132];
  uint local_14;
  
  local_14 = DAT_00829570 ^ (uint)auStack_f4;
  puVar1 = (undefined4 *)FUN_00633440(0x34,1);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_0076f81c;
    puVar1[2] = param_2;
    puVar1[3] = param_3;
    (**(code **)(*param_2 + 4))(param_3,DAT_02973abc,&local_e0,0);
    uVar2 = FUN_006267f0(puVar1,&DAT_0081f9a0,FUN_006cace0,param_2[4]);
    puVar1[1] = uVar2;
    FUN_00618e10(param_1,uVar2);
    if ((*(byte *)(param_2 + 7) & 8) != 0) {
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_b0);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"pos x",
                           auStack_98);
      puVar1[4] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 1;
      FUN_0061ee00(puVar1[1],puVar1[4]);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_ac);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"pos y",
                           auStack_98);
      puVar1[5] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 2;
      FUN_0061ee00(puVar1[1],puVar1[5]);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_a8);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"pos z",
                           auStack_98);
      puVar1[6] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 3;
      FUN_0061ee00(puVar1[1],puVar1[6]);
    }
    if ((*(byte *)(param_2 + 7) & 0x10) != 0) {
      FUN_005bf5e0(&local_e0,&fStack_e8,&fStack_e4,&fStack_ec);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)(int)fStack_e8 * 0.0054931640625);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"rot x",
                           auStack_98);
      puVar1[7] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 1;
      FUN_0061ee00(puVar1[1],puVar1[7]);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)(int)fStack_e4 * 0.0054931640625);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"rot y",
                           auStack_98);
      puVar1[8] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 2;
      FUN_0061ee00(puVar1[1],puVar1[8]);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)(int)fStack_ec * 0.0054931640625);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"rot z",
                           auStack_98);
      puVar1[9] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 3;
      FUN_0061ee00(puVar1[1],puVar1[9]);
    }
    if ((*(byte *)(param_2 + 7) & 0x20) != 0) {
      fStack_ec = fStack_d8 * fStack_d8 + local_e0 * local_e0 + fStack_dc * fStack_dc;
      fVar4 = (float10)FUN_005c0240();
      fStack_e4 = (float)fVar4;
      fStack_ec = fStack_c8 * fStack_c8 + fStack_d0 * fStack_d0 + fStack_cc * fStack_cc;
      fVar4 = (float10)FUN_005c0240();
      fStack_e8 = (float)fVar4;
      fStack_ec = fStack_b8 * fStack_b8 + fStack_c0 * fStack_c0 + fStack_bc * fStack_bc;
      fVar4 = (float10)FUN_005c0240();
      fStack_ec = (float)fVar4;
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_e4);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"scale x",
                           auStack_98);
      puVar1[10] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 1;
      FUN_0061ee00(puVar1[1],puVar1[10]);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_e8);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"scale y",
                           auStack_98);
      puVar1[0xb] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 2;
      FUN_0061ee00(puVar1[1],puVar1[0xb]);
      FUN_004f2740(auStack_98,&DAT_0076bd70,(double)fStack_ec);
      iVar3 = FUN_00626250(puVar1,&DAT_0081f9a0,FUN_006cace0,FUN_006c3b20,FUN_006cadc0,2,"scale z",
                           auStack_98);
      puVar1[0xc] = iVar3;
      *(undefined1 *)(iVar3 + 0x10) = 3;
      FUN_0061ee00(puVar1[1],puVar1[0xc]);
    }
  }
  __security_check_cookie(local_14 ^ (uint)auStack_f4);
  return;
}

