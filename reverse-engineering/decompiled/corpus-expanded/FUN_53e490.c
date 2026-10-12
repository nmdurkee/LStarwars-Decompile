/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53e490; label: FUN_0053e490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_0053e490(undefined4 *param_1,int param_2,short *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar4 = (int)*(short *)*param_1;
  iVar5 = 0;
  if (0 < iVar4) {
    do {
      iVar6 = iVar5 + -1;
      if (iVar6 < 0) {
        iVar6 = iVar4 + -1;
      }
      local_28 = iVar5 + 1;
      iVar8 = local_28;
      if (iVar4 <= local_28) {
        iVar8 = 0;
      }
      if (param_2 == 0) {
        iVar6 = iVar6 * 0xc;
        FUN_005b37d0(&local_18,*(int *)(param_1[1] + 8) + iVar6,*(int *)(param_1[2] + 8) + iVar6);
        if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
          FUN_005b37d0(&local_18,&local_18,*(int *)(param_1[3] + 8) + iVar6);
          FUN_005b37d0(&local_18,&local_18,*(int *)(param_1[4] + 8) + iVar6);
          uVar3 = 0x3e800000;
        }
        else {
          uVar3 = 0x3f000000;
        }
        FUN_005b3830(&local_18,&local_18,uVar3);
        iVar4 = iVar5 * 0xc;
        FUN_005b37d0(&local_24,*(int *)(param_1[1] + 8) + iVar4,*(int *)(param_1[2] + 8) + iVar4);
        if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
          FUN_005b37d0(&local_24,&local_24,*(int *)(param_1[3] + 8) + iVar4);
          FUN_005b37d0(&local_24,&local_24,*(int *)(param_1[4] + 8) + iVar4);
          uVar3 = 0x3e800000;
        }
        else {
          uVar3 = 0x3f000000;
        }
        FUN_005b3830(&local_24,&local_24,uVar3);
        iVar8 = iVar8 * 0xc;
        FUN_005b37d0(&local_c,*(int *)(param_1[1] + 8) + iVar8,*(int *)(param_1[2] + 8) + iVar8);
        if ((*(byte *)(param_1 + 0x1a) & 1) == 0) {
          FUN_005b37d0(&local_c,&local_c,*(int *)(param_1[3] + 8) + iVar8);
          FUN_005b37d0(&local_c,&local_c,*(int *)(param_1[4] + 8) + iVar8);
          uVar3 = 0x3e800000;
        }
        else {
          uVar3 = 0x3f000000;
        }
        FUN_005b3830(&local_c,&local_c,uVar3);
      }
      else {
        iVar2 = *(int *)(param_2 + 8);
        local_18 = *(undefined4 *)(iVar2 + iVar6 * 0xc);
        iVar4 = iVar2 + iVar6 * 0xc;
        local_14 = *(undefined4 *)(iVar4 + 4);
        local_10 = *(undefined4 *)(iVar4 + 8);
        local_24 = *(undefined4 *)(iVar2 + iVar5 * 0xc);
        iVar4 = iVar2 + iVar5 * 0xc;
        local_20 = *(undefined4 *)(iVar4 + 4);
        local_1c = *(undefined4 *)(iVar4 + 8);
        puVar1 = (undefined4 *)(iVar2 + iVar8 * 0xc);
        local_c = *puVar1;
        local_8 = puVar1[1];
        local_4 = puVar1[2];
      }
      local_30 = 0;
      local_2c = 0;
      uVar7 = 2;
      if (iVar5 == 0) {
        if (*(char *)((int)param_1 + 0x33) == '\0') {
          FUN_0053e410(&local_30,&local_2c);
          uVar7 = 1;
        }
        else {
LAB_0053e72c:
          FUN_0053e410(&local_30,&local_2c);
          FUN_0053e410((int)&local_30 + 2,(int)&local_2c + 2);
        }
      }
      else {
        if ((iVar5 != *(short *)*param_1 + -1) || (*(char *)((int)param_1 + 0x33) != '\0'))
        goto LAB_0053e72c;
        FUN_0053e410(&local_30,&local_2c);
        uVar7 = 1;
      }
      *param_3 = (short)local_30;
      param_3[1] = (short)local_2c;
      if (1 < uVar7) {
        iVar5 = (local_30 >> 0x10) - (local_30 & 0xffff);
        if (iVar5 < 0x8001) {
          if (iVar5 < -0x8000) {
            iVar5 = iVar5 + 0x10000;
          }
        }
        else {
          iVar5 = iVar5 + -0x10000;
        }
        *param_3 = (short)(iVar5 / 2) + (short)local_30;
        iVar5 = (local_2c >> 0x10) - (local_2c & 0xffff);
        if (iVar5 < 0x8001) {
          if (iVar5 < -0x8000) {
            iVar5 = iVar5 + 0x10000;
          }
        }
        else {
          iVar5 = iVar5 + -0x10000;
        }
        param_3[1] = (short)(iVar5 / 2) + (short)local_2c;
      }
      iVar4 = (int)*(short *)*param_1;
      param_3 = param_3 + 2;
      iVar5 = local_28;
    } while (local_28 < iVar4);
  }
  return param_3;
}

