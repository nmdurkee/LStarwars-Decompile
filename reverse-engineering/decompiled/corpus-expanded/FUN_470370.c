/* Ghidra pseudocode, not original source.
 * ev_d9512b1cdbab5300ab403012014fa5708c5416e00a513842278be36b13b8a77c
 * Entry: 0x470370; label: FUN_00470370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00470370(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if ((((DAT_00951288 == 0) && ((*(byte *)(*(int *)(param_1 + 0x128) + 100) & 0xe0) == 0)) &&
      (*(int *)(param_1 + 0x46ec) == 0)) &&
     (iVar2 = FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),&local_c,"grabber",1), iVar2 != 0)) {
    uVar3 = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
    *(uint *)(param_1 + 0x46ec) = uVar3;
    *(uint *)(param_1 + 0x104) = uVar3 + 0x568;
    puVar6 = *(undefined4 **)(param_1 + 0x46ec);
    DAT_00879468 = puVar6;
    puVar6[0x13f] = local_c;
    puVar6[0x140] = local_8;
    puVar6[0x141] = local_4;
    iVar2 = FUN_004fc900("grabbers",param_2,0xffff);
    if (iVar2 != 0) {
      FUN_004f10e0(iVar2,&PTR_s_radius_007f91b8);
      bVar1 = false;
      iVar4 = FUN_004fc5b0(iVar2);
      while (iVar4 != 0) {
        iVar4 = FUN_004f7fb0(iVar2);
        if (iVar4 != 0) {
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"grabber_start");
          if (iVar4 == 0) {
            *(undefined1 *)((int)DAT_00879468 + 0x562) = 0;
            DAT_00879468[0x14e] = 0x3f000000;
            bVar1 = true;
            DAT_00879468[0x14d] = 0x3f800000;
            *(byte *)((int)DAT_00879468 + 0x559) = *(byte *)((int)DAT_00879468 + 0x559) & 0xf7;
            DAT_00879468[0x14c] = 0x3f800000;
            *(undefined1 *)((int)DAT_00879468 + 0x563) = 0;
            *(byte *)((int)DAT_00879468 + 0x559) = *(byte *)((int)DAT_00879468 + 0x559) | 0x10;
            *(undefined2 *)((int)DAT_00879468 + 0x55e) = DAT_007f1980;
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar2 + 0x510),"grabber_end");
            if (iVar4 == 0) break;
            if (bVar1) {
              FUN_004fa020(iVar2);
            }
          }
        }
        iVar4 = FUN_004fc5b0(iVar2);
      }
      FUN_004fa300(iVar2);
      if (*(short *)((int)DAT_00879468 + 0x55e) == -1) {
        DAT_00879468[300] = 0;
      }
      else {
        uVar5 = FUN_0062df80((int)*(short *)((int)DAT_00879468 + 0x55e));
        DAT_00879468[300] = uVar5;
      }
      if (DAT_00879468[300] == 0) {
        FUN_005cfc00(DAT_00879468 + 0x13f,1);
        *(undefined2 *)((int)DAT_00879468 + 0x55e) = 0xffff;
      }
      else {
        FUN_005cfc00(DAT_00879468 + 0x13f,0);
      }
      puVar6 = (undefined4 *)FUN_005d0330(DAT_00879468 + 0x13f);
      puVar7 = DAT_00879468;
      for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      if (*(int *)(param_1 + 0x128) == DAT_0087b1a4) {
        DAT_00879468[0xd] = (float)DAT_00879468[0xd] + _DAT_007f91b4;
      }
      FUN_004ef660(DAT_00879468 + 0x120,DAT_00879468 + 0xc,0xc);
      FUN_005cf5b0(*(undefined4 *)(param_1 + 0x13c),DAT_00879468 + 0x142,"grabber_shadow",1);
      *(undefined2 *)(*(int *)(param_1 + 0x46ec) + 0x560) = 0xffff;
    }
  }
  return;
}

