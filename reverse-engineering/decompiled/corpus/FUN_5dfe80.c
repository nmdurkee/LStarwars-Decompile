/* Ghidra analysis pseudocode, not original source.
 * ev_c81f74825c4c1caab95b487b54d809df2f5062ed260a25fe246075816e66607e
 * Entry: 0x5dfe80; label: FUN_005dfe80
 */

void FUN_005dfe80(int *param_1,int *param_2,int *param_3,int param_4)

{
  int *piVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  byte bVar6;
  byte *pbVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  float *pfVar12;
  int *piVar13;
  uint *puVar14;
  int *piVar15;
  int *local_820;
  int *local_81c;
  uint *local_818;
  int *local_814;
  uint local_810;
  int *local_80c;
  undefined4 local_808;
  ushort auStack_804 [1024];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_820;
  local_81c = param_1;
  local_80c = param_3;
  if (param_1 != (int *)0x0) {
    local_820 = (int *)param_1[2];
    piVar13 = param_2;
    if (param_4 != 0) {
      piVar13 = (int *)0x0;
      piVar15 = (int *)0x0;
      if (param_2 == (int *)0x0) goto LAB_005e01db;
      piVar1 = local_820 + 0x24;
      do {
        bVar6 = FUN_006042e0(local_820 + 0x20,piVar1,param_3,0,0);
        if (bVar6 != 0) {
          auStack_804[(int)piVar13] = (ushort)bVar6 << 8 | (ushort)piVar15;
          piVar13 = (int *)((int)piVar13 + 1);
        }
        piVar15 = (int *)((int)piVar15 + 1);
        param_3 = param_3 + 0x10;
      } while (piVar15 < param_2);
    }
    local_814 = piVar13;
    if (piVar13 != (int *)0x0) {
      pfVar12 = (float *)local_820[0x2f];
      fVar2 = *pfVar12;
      for (puVar14 = (uint *)local_820[0x2c]; (0.0 < fVar2 && (*puVar14 == 0));
          puVar14 = puVar14 + 3) {
        fVar2 = pfVar12[1];
        pfVar12 = pfVar12 + 1;
      }
      iVar3 = *(int *)(*local_81c + 0x110);
      *(uint *)(iVar3 + 0x74) = *(uint *)(iVar3 + 0x74) | 2;
      local_810 = 0;
      local_818 = puVar14;
      if (*puVar14 != 0) {
        do {
          iVar4 = *(int *)(*(int *)(*(int *)(iVar3 + 0x50) +
                                   *(int *)(puVar14[1] + local_810 * 4) * 4) + 0x3c);
          uVar11 = *(uint *)(iVar4 + 4);
          pbVar7 = (byte *)(((int)(uVar11 + ((int)uVar11 >> 0x1f & 7U)) >> 3) +
                           *(int *)(iVar3 + 0x58 + (*(uint *)(iVar3 + 0x74) >> 0xf & 1) * 4));
          uVar11 = uVar11 & 0x80000007;
          if ((int)uVar11 < 0) {
            uVar11 = (uVar11 - 1 | 0xfffffff8) + 1;
          }
          *pbVar7 = *pbVar7 | '\x01' << ((byte)uVar11 & 0x1f);
          FUN_00607590(iVar4,&DAT_009868a0);
          uVar8 = FUN_00603530(iVar4,(int)local_814 * 2);
          pcVar9 = (char *)(*(int *)(iVar3 + 8) + *(int *)(puVar14[2] + local_810 * 4) * 0x10);
          if (*pcVar9 == -0x71) {
            local_81c = (int *)0x0;
            if (local_814 != (int *)0x0) {
              local_820 = local_80c;
              do {
                piVar13 = local_820;
                if (param_4 != 0) {
                  piVar13 = local_80c + (uint)(byte)auStack_804[(int)local_81c] * 0x10;
                }
                local_808 = FUN_00603610(uVar8,piVar13,
                                         *(undefined4 *)
                                          (*(int *)(iVar3 + 0x50) + *(int *)(iVar4 + 4) * 4),
                                         *(undefined4 *)
                                          (*(int *)(local_818[2] + local_810 * 4) * 0x10 + 4 +
                                          *(int *)(iVar3 + 8)));
                uVar10 = FUN_00603970(uVar8,*(undefined4 *)
                                             (*(int *)(local_818[2] + local_810 * 4) * 0x10 + 4 +
                                             *(int *)(iVar3 + 8)),piVar13);
                **(undefined1 **)(iVar4 + 0x24) = 0x90;
                *(undefined1 *)(*(int *)(iVar4 + 0x24) + 1) = 3;
                *(undefined4 *)(*(int *)(iVar4 + 0x24) + 4) = local_808;
                *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 0x10;
                puVar5 = *(undefined1 **)(iVar4 + 0x24);
                *puVar5 = 0x8f;
                *(undefined1 *)(*(int *)(iVar4 + 0x24) + 1) = 3;
                *(undefined4 *)(*(int *)(iVar4 + 0x24) + 4) = uVar10;
                *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 0x10;
                FUN_00603ad0(puVar5 + -0x10,*(int *)(iVar4 + 0x24) + -0x10,0x3f800000);
                local_820 = local_820 + 0x10;
                local_81c = (int *)((int)local_81c + 1);
                puVar14 = local_818;
              } while (local_81c < local_814);
            }
          }
          else {
            local_820 = *(int **)(pcVar9 + 4);
            piVar13 = (int *)0x0;
            puVar14 = local_818;
            if (local_814 != (int *)0x0) {
              local_81c = local_80c;
              do {
                piVar15 = local_81c;
                if (param_4 != 0) {
                  piVar15 = local_80c + (uint)(byte)auStack_804[(int)piVar13] * 0x10;
                }
                uVar10 = FUN_00603580(uVar8,piVar15,
                                      *(undefined4 *)
                                       (*(int *)(iVar3 + 0x50) + *(int *)(iVar4 + 4) * 4),local_820,
                                      0);
                **(undefined1 **)(iVar4 + 0x24) = 0x8c;
                *(undefined1 *)(*(int *)(iVar4 + 0x24) + 1) = 3;
                *(undefined4 *)(*(int *)(iVar4 + 0x24) + 4) = uVar10;
                *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 0x10;
                puVar5 = *(undefined1 **)(iVar4 + 0x24);
                *puVar5 = 0x82;
                *(undefined1 *)(*(int *)(iVar4 + 0x24) + 1) = 3;
                *(int **)(*(int *)(iVar4 + 0x24) + 4) = local_820;
                *(int *)(iVar4 + 0x24) = *(int *)(iVar4 + 0x24) + 0x10;
                FUN_00603ad0(puVar5 + -0x10,*(int *)(iVar4 + 0x24) + -0x10,0x3f800000);
                local_81c = local_81c + 0x10;
                piVar13 = (int *)((int)piVar13 + 1);
                puVar14 = local_818;
              } while (piVar13 < local_814);
            }
          }
          local_810 = local_810 + 1;
        } while (local_810 < *puVar14);
      }
    }
  }
LAB_005e01db:
  __security_check_cookie(local_4 ^ (uint)&local_820);
  return;
}

