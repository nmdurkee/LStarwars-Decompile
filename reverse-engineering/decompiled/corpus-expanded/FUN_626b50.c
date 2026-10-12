/* Ghidra pseudocode, not original source.
 * ev_d2141175d7fdb31f80696454dffb563fb6f914ee7c013e44c78745164b884694
 * Entry: 0x626b50; label: FUN_00626b50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00626b50(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  bool bVar8;
  int local_14;
  int local_10;
  int local_c;
  
  iVar6 = param_1[5];
  local_14 = param_1[6];
  DAT_02854d1c = DAT_02854d1c + 1;
  local_c = 0;
  FUN_00600b20(0);
  FUN_005d0a40(1);
  FUN_005d0880(2);
  if (DAT_02912eb8 == 0) {
    FUN_005d0fb0(DAT_02912b38);
  }
  FUN_005d0fe0(DAT_02912b38,_DAT_0080f558,_DAT_0080f55c);
  FUN_005d0e80(DAT_02912b38);
  iVar2 = FUN_006e6b90();
  FUN_005d0e80(DAT_02912b38);
  FUN_005d0eb0(DAT_02912b38);
  iVar3 = FUN_006e6b90();
  if (((char *)param_1[0xd] != (char *)0x0) && (*(char *)param_1[0xd] != '\0')) {
    if (param_1[0xf] == 0) {
      FUN_0061f340((float)iVar6,(float)local_14,(float)param_1[7],(float)iVar2,0,FUN_0061f1a0,0x40,0
                  );
    }
    if (DAT_02912eb8 == 0) {
      FUN_005db880(iVar6 << 4,local_14 * 8,param_1[7] << 4,iVar2 * 8,0x80000000,
                   (&DAT_02900c70)[DAT_02912e90]);
      if (DAT_02912eb8 == 0) {
        FUN_005d0fb0(DAT_02912b38);
        if (DAT_02912eb8 == 0) {
          FUN_005d1060(DAT_02912b38,0x807f7f7f);
        }
      }
    }
    FUN_00618420(iVar3 + local_14 * 8,0x10,iVar6 << 4,param_1[7] << 4,param_1[0xd]);
    local_14 = local_14 + iVar2;
  }
  piVar7 = (int *)param_1[3];
  iVar2 = local_14;
  if (piVar7 != (int *)0x0) {
    bVar8 = param_1[2] != 0;
    if (piVar7 != (int *)*param_1) {
      FUN_005d0e80(DAT_02912b38);
      iVar2 = FUN_006e6b90();
      if (param_1[0xf] == 0) {
        FUN_0061f340((float)iVar6,(float)local_14,(float)param_1[7],(float)iVar2,0,FUN_0061f230,0x40
                     ,0);
      }
      if (DAT_02912eb8 == 0) {
        FUN_005db880(iVar6 << 4,local_14 * 8,param_1[7] << 4,iVar2 * 8,0x80000000,
                     (&DAT_02900c70)[DAT_02912e90]);
        if (DAT_02912eb8 == 0) {
          iVar3 = (iVar2 + local_14) * 8 + -0x10;
          FUN_005db5b0((param_1[7] + iVar6 * 2) * 8,local_14 * 8 + 8,
                       (param_1[7] + 4 + iVar6 * 2) * 8 + iVar2 * -0x10,iVar3,0x80ffffff,
                       DAT_02900c70);
          if (DAT_02912eb8 == 0) {
            FUN_005db5b0((param_1[7] + iVar6 * 2) * 8,local_14 * 8 + 8,
                         (param_1[7] + -4 + (iVar2 + iVar6) * 2) * 8,iVar3,0x80ffffff,DAT_02900c70);
          }
        }
      }
      local_14 = local_14 + iVar2;
    }
    local_c = 0;
    param_1[4] = (int)piVar7;
    iVar2 = local_14;
    local_10 = iVar6;
    if (piVar7 != (int *)0x0) {
      while( true ) {
        if ((piVar7 == (int *)param_1[2]) && (bVar8 = false, param_1[0xf] == 0)) {
          uVar4 = 1;
        }
        else {
          uVar4 = 0;
        }
        iVar3 = FUN_0061ef20(piVar7,param_1,iVar6,iVar2,param_1[7],uVar4);
        if (local_c < iVar3) {
          local_c = iVar3;
        }
        if (param_1[0xf] == 0) {
          FUN_0061f340((float)local_10,(float)local_14,(float)param_1[7],(float)iVar3,piVar7,
                       piVar7[0x12],0x40,0);
        }
        piVar7 = (int *)*piVar7;
        if ((*(byte *)(param_1 + 0xe) & 2) == 0) {
          iVar2 = iVar2 + iVar3;
          local_14 = iVar2;
        }
        else {
          iVar6 = iVar6 + param_1[7];
          local_10 = iVar6;
        }
        if (piVar7 == (int *)0x0) goto LAB_00627081;
        if (param_1[8] + param_1[6] <= iVar2) break;
        param_1[4] = (int)piVar7;
      }
      FUN_005d0e80(DAT_02912b38);
      iVar3 = FUN_006e6b90();
      if (param_1[0xf] == 0) {
        FUN_0061f340((float)local_10,(float)local_14,(float)param_1[7],(float)iVar3,0,FUN_0061f260,
                     0x40,0);
      }
      if (DAT_02912eb8 == 0) {
        FUN_005db880(iVar6 << 4,iVar2 * 8,param_1[7] << 4,iVar3 * 8,0x80000000,
                     (&DAT_02900c70)[DAT_02912e90]);
        if (DAT_02912eb8 == 0) {
          iVar1 = (iVar3 + iVar2) * 8 + -0x10;
          FUN_005db5b0((param_1[7] + iVar6 * 2) * 8,iVar1,
                       (param_1[7] + 4 + iVar6 * 2) * 8 + iVar3 * -0x10,iVar2 * 8 + 8,0x80ffffff,
                       DAT_02900c70);
          if (DAT_02912eb8 == 0) {
            FUN_005db5b0((param_1[7] + iVar6 * 2) * 8,iVar1,
                         (param_1[7] + -4 + (iVar3 + iVar6) * 2) * 8,iVar2 * 8 + 8,0x80ffffff,
                         DAT_02900c70);
          }
        }
      }
    }
LAB_00627081:
    if ((bVar8) && (*(int *)param_1[3] != 0)) {
      param_1[3] = *(int *)param_1[3];
    }
  }
  if ((*(byte *)(param_1 + 0xe) & 2) == 0) {
    iVar6 = param_1[7] + param_1[5];
  }
  else {
    iVar2 = iVar2 + local_c;
  }
  iVar6 = iVar6 - param_1[5];
  iVar2 = iVar2 - param_1[6];
  bVar8 = param_1 == DAT_02912eac;
  param_1[9] = iVar6;
  param_1[10] = iVar2;
  if (bVar8) {
    if (DAT_02912eb8 != 0) goto LAB_00627123;
    uVar4 = (&DAT_02900c70)[DAT_02912e94];
    uVar5 = DAT_0080f540;
  }
  else {
    if (DAT_02912eb8 != 0) goto LAB_00627123;
    uVar4 = (&DAT_02900c70)[DAT_02912e94];
    uVar5 = DAT_0080f53c;
  }
  FUN_005dbbf0(param_1[5] * 0x10 + -0x10,param_1[6] * 8 + -8,(iVar6 + 2) * 0x10,iVar2 * 8 + 0x10,
               uVar5,uVar4);
LAB_00627123:
  if (param_1[0xf] != 0) {
    FUN_0061f340((float)param_1[5],(float)param_1[6],(float)param_1[9],(float)param_1[10],0,
                 FUN_0061f310,0x40,1);
    FUN_00626b50(param_1[0xf]);
  }
  FUN_005d08c0();
  FUN_005d0a70();
  DAT_02854d1c = DAT_02854d1c + -1;
  FUN_00600b20();
  return;
}

