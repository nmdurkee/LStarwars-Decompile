/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b08d0; label: FUN_004b08d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Removing unreachable block (ram,0x004b0b5c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b08d0(float param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_48;
  int local_44;
  undefined4 local_40 [16];
  
  iVar5 = FUN_0055f450();
  iVar3 = (int)param_1;
  iVar6 = *(int *)((int)param_1 + 0xca4);
  if (*(char *)((int)param_1 + 0x280) == -1) {
    return 0;
  }
  if (((DAT_0087b0f8 != 0) && (*(int *)(iVar5 + 0x128) == DAT_0087b0f8)) &&
     (*(int *)(iVar5 + 0x2988) != 0)) {
    *(undefined1 *)((int)param_1 + 0x107a) = 4;
    if ((*(char *)((int)param_1 + 0x671) != -1) &&
       ((*(byte *)(*(char *)((int)param_1 + 0x671) * 0x13c + 0x68 + **(int **)(iVar5 + 0x2988)) & 1)
        == 0)) {
      *(undefined1 *)((int)param_1 + 0x107a) = 4;
      param_1 = (float)((DAT_007fc018 * 0x10000) / 0x168);
      local_44 = FUN_006e6b90();
      param_1 = (float)((DAT_007fc01c * 0x10000) / 0x168);
      local_48 = FUN_006e6b90();
      if (*(char *)(iVar3 + 0x671) != -1) {
        FUN_00540d20(*(undefined4 *)(iVar5 + 0x2988),iVar3 + 0x670,local_40,DAT_007fc010,
                     DAT_007fc014);
        puVar7 = local_40;
        puVar8 = (undefined4 *)(iVar3 + 0xc04);
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
      }
      if ((*(byte *)(iVar3 + 0xe20) & 0x20) == 0) {
        *(undefined4 *)(iVar3 + 0xf20) = 0;
        *(undefined4 *)(iVar3 + 0xf1c) = 0;
        pfVar1 = (float *)(iVar3 + 0xf18);
        *pfVar1 = 0.0;
        param_1 = (*(float *)(iVar6 + 0x28) /
                  *(float *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x1c)) * _DAT_007fc020;
        if (0.0 < param_1) {
          *pfVar1 = *(float *)(iVar6 + 0x2c) * param_1;
          *(float *)(iVar3 + 0xf1c) = -*(float *)(iVar6 + 0x30) * param_1;
        }
        FUN_00499300(iVar3,1,1,1);
        *(undefined4 *)(iVar3 + 0xf20) = 0;
        FUN_005b3200(pfVar1,pfVar1,iVar3 + 0xc04);
        FUN_00499be0(iVar3);
        FUN_0054fb80(iVar3 + 0x68,iVar3 + 0x68,pfVar1,
                     *(undefined4 *)(*(int *)(*(int *)(iVar3 + 0x54) + 0x24) + 0x44));
      }
      else {
        FUN_00499170(iVar3,1,&param_1);
        if (param_1 != 0.0) {
          uVar4 = *(undefined2 *)((int)param_1 + 0x27a);
          *(undefined2 *)(iVar3 + 0x27a) = uVar4;
          *(undefined2 *)(iVar3 + 0x5a) = uVar4;
          *(undefined2 *)(iVar3 + 0x58) = uVar4;
          *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)((int)param_1 + 0x68);
          *(undefined4 *)(iVar3 + 0x6c) = *(undefined4 *)((int)param_1 + 0x6c);
          *(undefined4 *)(iVar3 + 0x70) = *(undefined4 *)((int)param_1 + 0x70);
          uVar2 = *(undefined4 *)((int)param_1 + 0xdc8);
          *(undefined2 *)(iVar3 + 0xe18) = 0;
          *(undefined2 *)(iVar3 + 0xe1c) = 0;
          *(undefined4 *)(iVar3 + 0xdc8) = uVar2;
          *(undefined2 *)(iVar3 + 0xe1a) = 0;
          *(undefined2 *)(iVar3 + 0x27c) = 0;
          *(undefined2 *)(iVar3 + 0x278) = 0;
          puVar7 = (undefined4 *)((int)param_1 + 0xc04);
          puVar8 = (undefined4 *)(iVar3 + 0xc04);
          for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar7 = (undefined4 *)((int)param_1 + 0x670);
          puVar8 = (undefined4 *)(iVar3 + 0x670);
          for (iVar6 = 0xe; iVar6 != 0; iVar6 = iVar6 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
      }
      param_1 = 1.0;
      if (DAT_0087b8e4 != 0) {
        iVar6 = FUN_006e6b90();
        local_48 = iVar6 * local_48;
        local_44 = iVar6 * local_44;
      }
      uVar4 = FUN_00550070(*(undefined2 *)(iVar3 + 0xe1c),local_44,0x40a00000);
      *(undefined2 *)(iVar3 + 0xe1c) = uVar4;
      uVar4 = FUN_00550070(*(undefined2 *)(iVar3 + 0xe18),local_44,0x40a00000);
      *(undefined2 *)(iVar3 + 0xe18) = uVar4;
      uVar4 = FUN_00550070(*(undefined2 *)(iVar3 + 0xe1a),local_48,0x40a00000);
      *(undefined2 *)(iVar3 + 0xe1a) = uVar4;
      return 1;
    }
  }
  return 0;
}

