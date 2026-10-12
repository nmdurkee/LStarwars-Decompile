/* Ghidra pseudocode, not original source.
 * ev_e29f926c447264a3e79b54e28a3bd4babd6a11bd163f218199d416ac4d0e9917
 * Entry: 0x425fa0; label: FUN_00425fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00425fa0(int param_1)

{
  short sVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  uint local_1c0;
  undefined2 *local_1bc;
  int local_1b8;
  uint local_1b4;
  int local_1b0;
  uint local_1ac;
  int local_1a8;
  int local_1a4;
  int local_1a0;
  short *local_19c;
  int local_198;
  int local_194;
  int local_190;
  int local_18c;
  int local_188;
  undefined4 local_184 [16];
  undefined1 local_144 [324];
  
  iVar3 = FUN_0055f450();
  if ((param_1 != 0) && (*(int *)(*(int *)(iVar3 + 0x2ac4) + 0x48) != 0)) {
    FUN_004246f0(&local_1b4,&local_198);
    local_1ac = 0xffffffff;
    if (local_198 == 1) {
      if ((&DAT_0087b6ca)[local_1b4] == '\0') {
        local_1ac = local_1b4;
      }
      else {
        local_1ac = (uint)(local_1b4 == 0);
      }
    }
    local_1b0 = param_1 + 0x178;
    local_1a0 = param_1 + 0x268;
    local_19c = (short *)(param_1 + 0x6c);
    local_1bc = &DAT_0086e4ec;
    local_1c0 = 0;
    local_1b8 = 0;
    local_1a4 = 0;
    do {
      iVar5 = local_1a4;
      sVar1 = *local_19c;
      local_1b4 = FUN_0062df80((int)sVar1);
      if ((local_1b4 != 0) && (*(char *)(param_1 + 0xa6e + local_1c0) == '\0')) {
        iVar8 = sVar1 * 0x120 + DAT_0093b284;
        local_1a8 = (int)*(char *)(iVar8 + 0x111);
        if ((local_1a8 != -1) && (*(int *)(local_1b4 + 0x14 + local_1a8 * 4) == 0)) {
          local_1a8 = -1;
        }
        local_194 = (&DAT_00856984)[local_1c0];
        local_190 = iVar8;
        FUN_00636010(local_144,1);
        FUN_006371d0(*(undefined4 *)(iVar3 + 0x2ab4),local_144,(int)&DAT_00856904 + iVar5,0,
                     0xffffffff,0x3f800000);
        FUN_00595540(local_144,0x3f800000);
        uVar4 = FUN_004243e0(local_1bc,local_194,iVar8);
        FUN_005b4670(local_184,(ushort)(&DAT_0085697c)[local_1c0] + 0x8000);
        FUN_005b4900(local_184,(int)&DAT_00856904 + iVar5);
        iVar5 = FUN_0041cb50(local_1b4,local_1b0,local_184,0,0,local_1a0,0,uVar4);
        if (iVar5 != 0) {
          if (local_1a8 != -1) {
            iVar5 = 0;
            do {
              iVar8 = *(int *)(iVar3 + 0x5120 + iVar5 * 4);
              if (((iVar8 != 0) && (0 < *(int *)(param_1 + 0x48 + iVar5 * 4))) &&
                 (*(char *)(*(int *)(param_1 + iVar5 * 4) + 4) != '\0')) {
                uVar2 = local_1bc[iVar5];
                local_188 = (uint)uVar2 * 0x20 + iVar8 + 4;
                iVar8 = FUN_005cfac0(local_188);
                if (iVar8 != 0) {
                  iVar8 = *(int *)(param_1 + 0x24 + iVar5 * 4);
                  iVar6 = FUN_00574e20();
                  if (((iVar6 == 0xc) && (DAT_008569ac == 0)) &&
                     ((iVar5 == local_194 && ((local_198 == 2 || (local_1c0 == local_1ac)))))) {
                    FUN_005b7d30((&DAT_0085692c)[local_1c0],0x3e99999a);
                  }
                  else if ((iVar5 == 0) &&
                          ((*(byte *)(iVar8 + (uint)uVar2 * 0x28 + 0x12) & 0x20) != 0))
                  goto LAB_00426274;
                  puVar7 = (undefined4 *)((local_1b8 + local_1a8) * 0x40 + 0x268 + param_1);
                  puVar9 = local_184;
                  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
                    *puVar9 = *puVar7;
                    puVar7 = puVar7 + 1;
                    puVar9 = puVar9 + 1;
                  }
                  if (iVar5 == 0) {
                    FUN_005b4960(local_184,&DAT_0085698c + local_1a4);
                  }
                  FUN_005f33b0(local_188,local_184);
                }
              }
LAB_00426274:
              iVar5 = iVar5 + 1;
            } while (iVar5 < 9);
          }
          if (((0 < *(int *)(param_1 + 0x50)) &&
              (iVar5 = (int)*(char *)(local_190 + 0xf8), iVar5 != -1)) &&
             (*(int *)(local_1b4 + 0x14 + iVar5 * 4) != 0)) {
            iVar8 = *(int *)(param_1 + 0x2c) + (uint)(ushort)local_1bc[2] * 0x28;
            if ((*(short *)(iVar8 + 8) != -1) &&
               (*(char *)(*(short *)(iVar8 + 8) * 0x10 + 0xe + *(int *)(iVar3 + 0x2ac0)) != '\0')) {
              puVar7 = (undefined4 *)((local_1b8 + iVar5) * 0x40 + 0x268 + param_1);
              puVar9 = local_184;
              for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
                *puVar9 = *puVar7;
                puVar7 = puVar7 + 1;
                puVar9 = puVar9 + 1;
              }
              FUN_005f33b0(*(short *)(iVar8 + 8) * 0x10 + *(int *)(iVar3 + 0x2ac0),local_184);
              iVar5 = FUN_0049f800((int)*(short *)(iVar8 + 8),&local_18c);
              if (iVar5 != -1) {
                if ((local_18c != -1) &&
                   (iVar5 = local_18c * 0x10 + *(int *)(iVar3 + 0x2ac0), iVar5 != 0)) {
                  FUN_005f33b0(iVar5,local_184);
                }
                iVar5 = *(int *)(iVar3 + 0x2ac0) + 0x110;
                if (iVar5 != 0) {
                  FUN_005f33b0(iVar5,local_184);
                }
              }
            }
          }
        }
      }
      local_19c = local_19c + 1;
      local_1a0 = local_1a0 + 0x400;
      local_1b0 = local_1b0 + 0x48;
      local_1b8 = local_1b8 + 0x10;
      local_1bc = local_1bc + 0x1c;
      local_1c0 = local_1c0 + 1;
      local_1a4 = local_1a4 + 0xc;
    } while ((int)local_1c0 < 2);
    FUN_00595660(*(undefined4 *)(iVar3 + 0x2ab4),0x3f800000);
  }
  return;
}

