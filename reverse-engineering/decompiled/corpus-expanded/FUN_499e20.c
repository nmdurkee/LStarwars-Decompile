/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x499e20; label: FUN_00499e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00499e20(float param_1)

{
  float *pfVar1;
  float fVar2;
  undefined2 uVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  undefined2 uVar7;
  int iVar8;
  undefined4 uVar9;
  float10 fVar10;
  float local_18;
  float local_14;
  float local_10;
  undefined4 local_4;
  
  iVar6 = (int)param_1;
  iVar8 = FUN_0055f450();
  iVar4 = *(int *)((int)param_1 + 0xca4);
  fVar2 = *(float *)(iVar4 + 0x2c);
  local_14 = *(float *)(iVar4 + 0x30);
  local_18 = *(float *)(iVar4 + 0x28);
  if (*(char *)((int)param_1 + 0x280) == -1) {
    return 0;
  }
  if ((((DAT_0087b0dc == 0) || (*(int *)(iVar8 + 0x128) != DAT_0087b0dc)) ||
      (*(int *)(iVar8 + 0x2988) == 0)) || (*(char *)((int)param_1 + 0x671) == -1)) {
    return 0;
  }
  uVar7 = *(undefined2 *)((int)param_1 + 0x7ce);
  *(undefined1 *)((int)param_1 + 0x107a) = 3;
  if ((*(char *)((int)param_1 + 0x7b5) == '#') || (*(char *)((int)param_1 + 0x7b5) == '$')) {
    *(undefined4 *)((int)param_1 + 0xf20) = 0;
    *(undefined4 *)((int)param_1 + 0xf1c) = 0;
    *(undefined4 *)((int)param_1 + 0xf18) = 0;
    FUN_00499be0(param_1);
    fVar10 = (float10)FUN_0054fb40(*(undefined4 *)((int)param_1 + 0x68),
                                   *(undefined4 *)((int)param_1 + 0xf18),0);
    *(float *)((int)param_1 + 0x68) = (float)fVar10;
    fVar10 = (float10)FUN_0054fb40(*(undefined4 *)((int)param_1 + 0x70),
                                   *(undefined4 *)((int)param_1 + 0xf20),0);
  }
  else {
    if ((*(byte *)((int)param_1 + 0xe20) & 0x20) != 0) {
      FUN_00499170(param_1,1,&local_14);
      if (local_14 != 0.0) {
        uVar3 = *(undefined2 *)((int)local_14 + 0x27a);
        *(undefined2 *)((int)param_1 + 0x27a) = uVar3;
        *(undefined2 *)((int)param_1 + 0x5a) = uVar3;
        *(undefined2 *)((int)param_1 + 0x58) = uVar3;
        *(undefined4 *)((int)param_1 + 0x68) = *(undefined4 *)((int)local_14 + 0x68);
        *(undefined4 *)((int)param_1 + 0x6c) = *(undefined4 *)((int)local_14 + 0x6c);
        *(undefined4 *)((int)param_1 + 0x70) = *(undefined4 *)((int)local_14 + 0x70);
        uVar9 = *(undefined4 *)((int)local_14 + 0xdc8);
        *(undefined2 *)((int)param_1 + 0xe18) = 0;
        *(undefined4 *)((int)param_1 + 0xdc8) = uVar9;
        *(undefined2 *)((int)param_1 + 0xe1c) = 0;
        *(undefined2 *)((int)param_1 + 0xe1a) = 0;
        *(undefined2 *)((int)param_1 + 0x27c) = 0;
        *(undefined2 *)((int)param_1 + 0x278) = 0;
      }
      goto LAB_0049a19f;
    }
    iVar4 = *(int *)((int)param_1 + 0x54);
    *(undefined4 *)((int)param_1 + 0xf1c) = 0;
    iVar8 = *(int *)(iVar4 + 0x24);
    local_4 = *(undefined4 *)(iVar8 + 0x44);
    if ((*(float *)((int)param_1 + 0x200) == 0.0) && (*(float *)((int)param_1 + 0x208) == 0.0)) {
      if (DAT_0087aa21 != '\0') {
        if (-1.0 <= *(float *)((int)param_1 + 0x5c)) {
          if (*(float *)((int)param_1 + 0x5c) <= 1.0) {
            param_1 = 0.0;
          }
          else {
            param_1 = -1.0;
          }
        }
        else {
          param_1 = 1.0;
        }
        local_14 = 0.0;
        local_18 = *(float *)(iVar8 + 0x1c);
        fVar2 = param_1;
      }
      param_1 = fVar2;
      *(undefined4 *)(iVar6 + 0xf20) = 0;
      pfVar1 = (float *)(iVar6 + 0xf18);
      if (local_18 <= 0.0) {
        *pfVar1 = 0.0;
      }
      else {
        *pfVar1 = local_18 * param_1;
        if (DAT_007fffec != 0) {
          *(float *)(iVar6 + 0xf20) = local_18 * local_14;
        }
      }
      if ((0.0 < *(float *)(iVar6 + 0x1018)) && ((*(byte *)(iVar6 + 0xe26) & 7) != 0)) {
        fVar2 = *(float *)(*(int *)(iVar4 + 0x24) + 0x1c) * 1.5;
        local_14 = *(float *)(iVar6 + 0x1018) / 0.4;
        if ((*(byte *)(iVar6 + 0xe26) & 7) == 3) {
          local_14 = *(float *)(iVar6 + 0xf20) * 0.5 + fVar2 * local_14;
          *(float *)(iVar6 + 0xf20) = local_14;
          if (fVar2 < local_14) {
            *(float *)(iVar6 + 0xf20) = fVar2;
          }
        }
        else {
          fVar5 = *(float *)(iVar6 + 0xf20) * 0.5 - fVar2 * local_14;
          *(float *)(iVar6 + 0xf20) = fVar5;
          local_10 = -fVar2;
          if (fVar5 < local_10) {
            *(float *)(iVar6 + 0xf20) = local_10;
          }
        }
      }
      FUN_005b3620(pfVar1,pfVar1,uVar7);
      FUN_00499be0(iVar6);
    }
    else {
      *(undefined4 *)((int)param_1 + 0xf18) = *(undefined4 *)((int)param_1 + 0x200);
      *(undefined4 *)((int)param_1 + 0xf20) = *(undefined4 *)((int)param_1 + 0x208);
      *(undefined4 *)((int)param_1 + 0x208) = 0;
      *(undefined4 *)((int)param_1 + 0x200) = 0;
    }
    fVar10 = (float10)FUN_0054fb40(*(undefined4 *)(iVar6 + 0x68),*(undefined4 *)(iVar6 + 0xf18),
                                   local_4);
    *(float *)(iVar6 + 0x68) = (float)fVar10;
    fVar10 = (float10)FUN_0054fb40(*(undefined4 *)(iVar6 + 0x70),*(undefined4 *)(iVar6 + 0xf20),
                                   local_4);
  }
  *(float *)(iVar6 + 0x70) = (float)fVar10;
LAB_0049a19f:
  *(undefined2 *)(iVar6 + 0x5a) = uVar7;
  uVar7 = FUN_00550070(*(undefined2 *)(iVar6 + 0x58),uVar7,0x41000000);
  *(undefined2 *)(iVar6 + 0x27a) = uVar7;
  *(undefined2 *)(iVar6 + 0x58) = uVar7;
  uVar7 = FUN_00550070(*(undefined2 *)(iVar6 + 0x278),0,0x41000000);
  *(undefined2 *)(iVar6 + 0x278) = uVar7;
  if ((*(char *)(iVar6 + 0x7b5) == '#') || (*(char *)(iVar6 + 0x7b5) == '$')) {
    uVar9 = 0;
  }
  else {
    local_10 = (float)((DAT_007fc02c * 0x10000) / 0x168);
    uVar9 = FUN_006e6b90();
  }
  uVar7 = FUN_00550070(*(undefined2 *)(iVar6 + 0xe18),uVar9,0x41000000);
  *(undefined2 *)(iVar6 + 0xe18) = uVar7;
  return 1;
}

