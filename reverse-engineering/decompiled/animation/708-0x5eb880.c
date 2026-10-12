
/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005eb880(int param_1,int *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 code *param_7,undefined4 param_8)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  byte local_1075;
  undefined1 local_1070 [12];
  undefined1 local_1064 [12];
  undefined1 local_1058 [24];
  undefined4 local_1040 [16];
  int local_1000 [1023];
  undefined4 uStack_4;
  
  uStack_4 = 0x5eb88a;
  if ((0x414e4933 < *param_2) && (*param_2 < 0x414e4936)) {
    FUN_005eb790(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  if (DAT_009738e4 < *(int *)(param_1 + 0x168)) {
    DAT_009738e4 = *(int *)(param_1 + 0x168);
  }
  local_1000[0x2fd] = 0x3f800000;
  local_1000[0x2fe] = 0x3f800000;
  local_1000[0x2ff] = 0x3f800000;
  FUN_005c9c40(param_2,param_3,local_1058);
  if (param_4 != 0) {
    _memset(local_1000 + 0x300,0,*(int *)(param_1 + 0x168) * 4);
    uVar7 = 0;
    if (0 < param_4) {
      iVar6 = *(int *)(param_1 + 0x178);
      do {
        iVar2 = uVar7 * 0x34 + param_5;
        uVar5 = (uint)*(byte *)(iVar2 + 0x30);
        if (((int)uVar5 < iVar6) &&
           (bVar1 = *(byte *)(uVar5 + *(int *)(param_1 + 0x17c)), bVar1 != 0xff)) {
          local_1000[bVar1 + 0x300] = iVar2;
        }
        uVar7 = (uint)(byte)((char)uVar7 + 1);
      } while ((int)uVar7 < param_4);
    }
  }
  local_1075 = 0;
  if (0 < *(int *)(param_1 + 0x168)) {
    uVar7 = 0;
    do {
      puVar9 = (undefined4 *)(uVar7 * 0x40 + param_6);
      if ((int)uVar7 < (int)(short)param_2[1]) {
        if (param_4 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = local_1000[uVar7 + 0x300];
        }
        iVar3 = (int)*(short *)((int)param_2 + 6) * uVar7;
        iVar2 = param_2[3] + iVar3 * 4;
        iVar3 = param_2[4] + iVar3;
        uVar5 = (uint)*(char *)(param_2[5] + uVar7);
        if (local_1075 == 0) {
          FUN_005ceee0(iVar2,iVar3,uVar5,local_1058,*(int *)(param_1 + 0x16c),local_1000,
                       local_1000 + (uint)*(byte *)(*(int *)(param_1 + 0x16c) + 0x50) * 3,local_1040
                       ,iVar6,local_1070,local_1064);
          if (param_7 != (code *)0x0) {
            (*param_7)(local_1040,param_8,local_1070,0,local_1064,0);
          }
        }
        else {
          iVar4 = *(int *)(param_1 + 0x16c) + uVar7 * 0x60;
          FUN_005ceee0(iVar2,iVar3,uVar5,local_1058,iVar4,local_1000 + uVar7 * 3,
                       local_1000 + (uint)*(byte *)(iVar4 + 0x50) * 3,local_1040,iVar6,0,0);
        }
        bVar1 = *(byte *)(uVar7 * 0x60 + 0x50 + *(int *)(param_1 + 0x16c));
        if (bVar1 == 0xff) {
          if ((uVar5 & 0x40) != 0) {
            local_1000[uVar7 * 3] = 0x3f800000;
            local_1000[uVar7 * 3 + 1] = 0x3f800000;
            local_1000[uVar7 * 3 + 2] = 0x3f800000;
          }
          puVar8 = local_1040;
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar9 = *puVar8;
            puVar8 = puVar8 + 1;
            puVar9 = puVar9 + 1;
          }
        }
        else {
          FUN_005c0500(puVar9,local_1040,(uint)bVar1 * 0x40 + param_6);
        }
      }
      else {
        puVar8 = &DAT_00806680;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar9 = *puVar8;
          puVar8 = puVar8 + 1;
          puVar9 = puVar9 + 1;
        }
      }
      local_1075 = local_1075 + 1;
      uVar7 = (uint)local_1075;
    } while ((int)uVar7 < *(int *)(param_1 + 0x168));
  }
  return;
}

