/* Ghidra pseudocode, not original source.
 * ev_7610d2e5ecab5d7a95653def000f5e9425ca0c842a62593dc010feaabdcb80b1
 * Entry: 0x518210; label: FUN_00518210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00518210(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined *puVar11;
  int *piVar12;
  int local_4c;
  int local_48;
  float afStack_3c [2];
  float fStack_34;
  undefined4 auStack_30 [2];
  undefined4 uStack_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 auStack_18 [12];
  undefined4 auStack_c [2];
  undefined4 uStack_4;
  
  local_24 = 0;
  local_20 = 0;
  iVar9 = 0;
  local_1c = 0x3f800000;
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x138c) = param_2;
    *(undefined4 *)(param_1 + 0x1390) = param_3;
    if (*(int *)(param_1 + 0x137c) != -0x40 && -1 < *(int *)(param_1 + 0x137c) + 0x40) {
      local_4c = 0;
      do {
        if (iVar9 < *(int *)(param_1 + 0x137c)) {
          puVar11 = (undefined *)(*(int *)(param_1 + 0x1380) + local_4c);
        }
        else {
          puVar11 = &DAT_00922268 + (iVar9 - *(int *)(param_1 + 0x137c)) * 0x58;
        }
        if (puVar11[0x4b] != '\0') {
          if (DAT_009238d8 != (code *)0x0) {
            iVar5 = FUN_005cfd60(puVar11 + 0x20);
            if (iVar5 == 0) {
              (*DAT_009238d8)(param_1,puVar11 + 0x20);
            }
          }
          iVar5 = FUN_005cfd60(puVar11 + 0x20);
          if (iVar5 != 0) {
            uVar6 = FUN_005d0330(puVar11 + 0x20);
            FUN_005b30a0(puVar11,puVar11 + 0x2c,uVar6);
            *(float *)(puVar11 + 0x10) = *(float *)(puVar11 + 0x14) + *(float *)(puVar11 + 4);
            *(float *)(puVar11 + 0x18) = *(float *)(puVar11 + 0x1c) + *(float *)(puVar11 + 4);
            if (puVar11[0x4a] != '\0') {
              FUN_005b3200(auStack_c,&local_24,uVar6);
              uVar6 = FUN_005be2d0(auStack_c[0],uStack_4);
              *(undefined4 *)(puVar11 + 0x38) = uVar6;
              uVar6 = FUN_005be590(uVar6,*(undefined4 *)(puVar11 + 0x3c));
              *(undefined4 *)(puVar11 + 0x38) = uVar6;
            }
          }
        }
        local_4c = local_4c + 0x58;
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(int *)(param_1 + 0x137c) + 0x40);
    }
    local_48 = 0;
    if (0 < *(int *)(param_1 + 0x24)) {
      piVar12 = (int *)(*(int *)(param_1 + 0x28) + 0x20);
      do {
        iVar9 = piVar12[1];
        iVar10 = (uint)*(byte *)(iVar9 + 0x10) * 0x5c;
        iVar5 = *(int *)(*piVar12 + 0x7c);
        if (((*(byte *)(iVar5 + 0x2b + iVar10) & 2) != 0) ||
           ((*(byte *)((uint)*(byte *)(iVar9 + 0x11) * 0x5c + 0x2b + iVar5) & 2) != 0)) {
          piVar2 = (int *)(iVar5 + 4 + iVar10);
          iVar9 = (uint)*(byte *)(iVar9 + 0x11) * 0x5c + iVar5;
          FUN_005b3800(auStack_30,iVar9 + 4,piVar2);
          FUN_005b3b30(afStack_3c,auStack_30);
          if ((float)piVar12[4] <= 1.0) {
            if (0.0 <= (float)piVar12[4]) {
              fVar3 = *(float *)(iVar9 + 0x10) * (float)piVar12[4] +
                      (1.0 - (float)piVar12[4]) * *(float *)(iVar5 + 0x10 + iVar10);
            }
            else {
              fVar3 = *(float *)(iVar5 + 0x10 + iVar10);
            }
          }
          else {
            fVar3 = *(float *)(iVar9 + 0x10);
          }
          piVar1 = piVar12 + -4;
          fVar4 = fVar3 * fStack_34;
          fStack_34 = -afStack_3c[0] * fVar3;
          *piVar1 = *piVar2;
          piVar12[-3] = piVar2[1];
          piVar12[-2] = piVar2[2];
          afStack_3c[0] = fVar4;
          FUN_005b3830(auStack_18,auStack_30,piVar12[4]);
          FUN_005b37d0(piVar1,piVar1,auStack_18);
          FUN_005b3830(auStack_18,afStack_3c,piVar12[5]);
          FUN_005b37d0(piVar1,piVar1,auStack_18);
          FUN_005bfe00(auStack_30[0],uStack_28);
          uVar6 = FUN_006e6b90();
          iVar9 = FUN_005be590(uVar6,piVar12[6]);
          piVar12[-1] = iVar9;
        }
        local_48 = local_48 + 1;
        piVar12 = piVar12 + 0xf;
      } while (local_48 < *(int *)(param_1 + 0x24));
    }
    puVar7 = (uint *)(param_1 + 0x8c);
    iVar9 = 4;
    do {
      uVar8 = *puVar7;
      if ((uVar8 & 1) != 0) {
        if (puVar7[-1] == 0) {
          uVar8 = uVar8 | 2;
        }
        else {
          uVar8 = uVar8 & 0xfffffffd;
        }
        *puVar7 = uVar8;
      }
      uVar8 = puVar7[0x4d];
      if ((uVar8 & 1) != 0) {
        if (puVar7[0x4c] == 0) {
          uVar8 = uVar8 | 2;
        }
        else {
          uVar8 = uVar8 & 0xfffffffd;
        }
        puVar7[0x4d] = uVar8;
      }
      uVar8 = puVar7[0x9a];
      if ((uVar8 & 1) != 0) {
        if (puVar7[0x99] == 0) {
          uVar8 = uVar8 | 2;
        }
        else {
          uVar8 = uVar8 & 0xfffffffd;
        }
        puVar7[0x9a] = uVar8;
      }
      uVar8 = puVar7[0xe7];
      if ((uVar8 & 1) != 0) {
        if (puVar7[0xe6] == 0) {
          uVar8 = uVar8 | 2;
        }
        else {
          uVar8 = uVar8 & 0xfffffffd;
        }
        puVar7[0xe7] = uVar8;
      }
      puVar7 = puVar7 + 0x134;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  return;
}

