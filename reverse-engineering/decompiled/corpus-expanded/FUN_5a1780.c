/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1780; label: FUN_005a1780
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1780(int param_1)

{
  float fVar1;
  ushort uVar2;
  undefined4 *puVar3;
  float fVar4;
  float fVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  byte bVar12;
  
  if (param_1 != 0) {
    iVar10 = FUN_004f1440(param_1);
    while (iVar9 = iVar10, iVar9 != 0) {
      iVar10 = FUN_004f1460(param_1,iVar9);
      uVar2 = *(ushort *)(iVar9 + 10);
      *(ushort *)(iVar9 + 10) = uVar2 & 0xfffe;
      if ((uVar2 & 2) == 0) {
        puVar3 = *(undefined4 **)(iVar9 + 0x18);
        bVar12 = 0;
        *(undefined4 *)(iVar9 + 0xc) = 0;
        bVar6 = true;
        bVar8 = true;
        bVar7 = true;
        for (; puVar3 != (undefined4 *)0x0; puVar3 = (undefined4 *)*puVar3) {
          iVar11 = FUN_005cfde0(puVar3 + 1);
          if (iVar11 != 0) {
            bVar12 = 1;
          }
          iVar11 = puVar3[4];
          if (iVar11 != 0) {
            if ((float)puVar3[6] <= (float)puVar3[7]) {
              fVar4 = 1.0;
            }
            else {
              fVar4 = -1.0;
            }
            fVar1 = *(float *)(iVar11 + 0x4c);
            fVar5 = fVar4 * *(float *)(iVar11 + 0x4c);
            if (fVar4 * (float)puVar3[7] < fVar5 == (fVar4 * (float)puVar3[7] == fVar5)) {
              if (fVar4 * *(float *)(iVar11 + 0x4c) <= fVar4 * (float)puVar3[6]) {
                if (*(float *)(iVar11 + 0x40) * fVar4 <= 0.0) {
                  if ((*(byte *)(iVar11 + 0x50) & 8) == 0) {
                    *(undefined4 *)(iVar11 + 0x4c) = puVar3[6];
                    goto LAB_005a1924;
                  }
                  *(float *)(iVar11 + 0x4c) =
                       (float)puVar3[7] - ((float)puVar3[6] - *(float *)(iVar11 + 0x4c));
                }
                else {
                  *(undefined4 *)(iVar11 + 0x4c) = puVar3[6];
                }
              }
            }
            else if (0.0 <= *(float *)(iVar11 + 0x40) * fVar4) {
              if ((*(byte *)(iVar11 + 0x50) & 8) == 0) {
                *(undefined4 *)(iVar11 + 0x4c) = puVar3[7];
LAB_005a1924:
                *(uint *)(puVar3[4] + 0x50) = *(uint *)(puVar3[4] + 0x50) & 0xfffffffe;
              }
              else {
                *(float *)(iVar11 + 0x4c) =
                     (*(float *)(iVar11 + 0x4c) - (float)puVar3[7]) + (float)puVar3[6];
              }
            }
            else {
              *(undefined4 *)(iVar11 + 0x4c) = puVar3[7];
            }
            if (*(float *)(puVar3[4] + 0x4c) != fVar1) {
              FUN_00552760(puVar3 + 1,*(undefined4 *)(puVar3[4] + 0x4c));
            }
            iVar11 = puVar3[4];
            if ((*(byte *)(iVar11 + 0x50) & 1) != 0) {
              *(ushort *)(iVar9 + 10) = *(ushort *)(iVar9 + 10) | 1;
              iVar11 = puVar3[4];
              if (*(float *)(iVar11 + 0x40) * fVar4 < 0.0) {
                bVar6 = false;
              }
            }
            fVar1 = *(float *)(iVar11 + 0x4c) * fVar4;
            if (fVar4 * (float)puVar3[6] < fVar1) {
              bVar8 = false;
            }
            if (fVar1 < (float)puVar3[7] * fVar4) {
              bVar7 = false;
            }
          }
        }
        if ((*(byte *)(iVar9 + 10) & 1) != bVar12) {
          for (puVar3 = *(undefined4 **)(iVar9 + 0x18); puVar3 != (undefined4 *)0x0;
              puVar3 = (undefined4 *)*puVar3) {
            FUN_005cfd90(puVar3 + 1,*(byte *)(iVar9 + 10) & 1);
          }
        }
        if ((*(ushort *)(iVar9 + 10) & 1) == 0) {
          if (bVar7) {
            *(undefined4 *)(iVar9 + 0xc) = 2;
          }
          else if (!bVar8) {
            *(undefined4 *)(iVar9 + 0xc) = 4;
          }
          if ((uVar2 & 1) != 0) {
            *(ushort *)(iVar9 + 10) = *(ushort *)(iVar9 + 10) | 2;
          }
        }
        else {
          *(uint *)(iVar9 + 0xc) = (uint)!bVar6 * 2 + 1;
        }
        if (((*(ushort *)(iVar9 + 10) & 3) == 0) && (*(int *)(iVar9 + 0x14) != 0)) {
          if ((*(ushort *)(iVar9 + 10) & 4) != 0) {
            FUN_004f1410(*(int *)(iVar9 + 0x14),iVar9);
            *(ushort *)(iVar9 + 10) = *(ushort *)(iVar9 + 10) & 0xfffb;
          }
          FUN_005a0670(iVar9);
        }
      }
      else {
        *(ushort *)(iVar9 + 10) = uVar2 & 0xfffc;
        if (*(int *)(iVar9 + 0x14) != 0) {
          if ((uVar2 & 4) != 0) {
            FUN_004f1410(*(int *)(iVar9 + 0x14),iVar9);
            *(ushort *)(iVar9 + 10) = *(ushort *)(iVar9 + 10) & 0xfffb;
          }
          FUN_005a0670(iVar9);
        }
      }
    }
  }
  return;
}

