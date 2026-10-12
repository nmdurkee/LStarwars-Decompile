/* Ghidra pseudocode, not original source.
 * ev_0733f146760cc31006e6190a74f2cd28d34a83dcf7f13916827ecd624512e4e0
 * Entry: 0x5f0ac0; label: FUN_005f0ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f0ac0(void)

{
  float *pfVar1;
  float fVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  int *piVar9;
  byte *pbVar10;
  float *pfVar11;
  int unaff_ESI;
  int iVar12;
  int local_68;
  int local_64;
  float local_50;
  float local_4c;
  float local_48;
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  float local_1c;
  float local_18;
  
  iVar12 = 0;
  local_64 = 0;
  if (0 < *(int *)(unaff_ESI + 0x10)) {
    local_68 = 0;
    do {
      pfVar11 = (float *)(*(int *)(unaff_ESI + 0x28) + iVar12 * 4);
      if (*(float *)(*(int *)(unaff_ESI + 0x28) + iVar12 * 4) == 0.0) {
        if ((*(byte *)(local_64 + *(int *)(unaff_ESI + 0x48)) & 0x20) != 0) {
          pfVar11 = (float *)(*(int *)(unaff_ESI + 0x44) + local_68);
          local_20 = *(float *)(*(int *)(unaff_ESI + 0x44) + local_68) - pfVar11[4];
          local_1c = pfVar11[1] - pfVar11[5];
          local_18 = pfVar11[2] - pfVar11[6];
          local_30 = *pfVar11 + pfVar11[4];
          local_2c = pfVar11[1] + pfVar11[5];
          local_28 = pfVar11[2] + pfVar11[6];
          cVar7 = FUN_005c6dc0(&local_20,&local_30,DAT_009718e0);
          if (cVar7 != '\0') {
            iVar8 = 0;
            piVar9 = (int *)(iVar12 * 0xc + *(int *)(unaff_ESI + 0x14));
            if (0 < *piVar9) {
              do {
                uVar3 = *(uint *)(piVar9[1] + iVar8 * 4);
                pbVar10 = (byte *)(*(int *)(unaff_ESI + 0x58 +
                                           (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4) +
                                  (uVar3 >> 3));
                iVar8 = iVar8 + 1;
                *pbVar10 = *pbVar10 | '\x01' << ((byte)uVar3 & 7);
                piVar9 = (int *)(iVar12 * 0xc + *(int *)(unaff_ESI + 0x14));
              } while (iVar8 < *piVar9);
            }
            pbVar10 = (byte *)(*(int *)(unaff_ESI + 0x30 +
                                       (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4) + (iVar12 >> 2)
                              );
            *pbVar10 = *pbVar10 | '\x01' << ((byte)iVar12 & 3) * '\x02';
          }
        }
      }
      else {
        if ((*(byte *)(local_64 + *(int *)(unaff_ESI + 0x48)) & 0x20) != 0) {
          fVar4 = DAT_00973718 - *(float *)(*(int *)(unaff_ESI + 0x44) + local_68);
          iVar8 = *(int *)(unaff_ESI + 0x44) + local_68;
          fVar5 = DAT_0097371c - *(float *)(iVar8 + 4);
          fVar6 = DAT_00973720 - *(float *)(iVar8 + 8);
          fVar2 = *pfVar11;
          while (fVar6 * fVar6 + fVar4 * fVar4 + fVar5 * fVar5 < fVar2) {
            pfVar1 = pfVar11 + 1;
            pfVar11 = pfVar11 + 1;
            iVar12 = iVar12 + 1;
            fVar2 = *pfVar1;
          }
          pfVar11 = (float *)(local_68 + *(int *)(unaff_ESI + 0x44));
          local_40 = *(float *)(local_68 + *(int *)(unaff_ESI + 0x44)) - pfVar11[4];
          local_3c = pfVar11[1] - pfVar11[5];
          local_38 = pfVar11[2] - pfVar11[6];
          local_50 = *pfVar11 + pfVar11[4];
          local_4c = pfVar11[1] + pfVar11[5];
          local_48 = pfVar11[2] + pfVar11[6];
          cVar7 = FUN_005c6dc0(&local_40,&local_50,DAT_009718e0);
          if (cVar7 != '\0') {
            iVar8 = 0;
            piVar9 = (int *)(iVar12 * 0xc + *(int *)(unaff_ESI + 0x14));
            if (0 < *piVar9) {
              do {
                uVar3 = *(uint *)(piVar9[1] + iVar8 * 4);
                pbVar10 = (byte *)(*(int *)(unaff_ESI + 0x58 +
                                           (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4) +
                                  (uVar3 >> 3));
                iVar8 = iVar8 + 1;
                *pbVar10 = *pbVar10 | '\x01' << ((byte)uVar3 & 7);
                piVar9 = (int *)(iVar12 * 0xc + *(int *)(unaff_ESI + 0x14));
              } while (iVar8 < *piVar9);
            }
            pbVar10 = (byte *)(*(int *)(unaff_ESI + 0x30 +
                                       (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4) + (iVar12 >> 2)
                              );
            *pbVar10 = *pbVar10 | '\x01' << ((byte)iVar12 & 3) * '\x02';
          }
        }
        iVar8 = *(int *)(unaff_ESI + 0x28) + iVar12 * 4;
        fVar2 = *(float *)(*(int *)(unaff_ESI + 0x28) + iVar12 * 4);
        while (fVar2 != 0.0) {
          pfVar11 = (float *)(iVar8 + 4);
          iVar8 = iVar8 + 4;
          iVar12 = iVar12 + 1;
          fVar2 = *pfVar11;
        }
      }
      local_64 = local_64 + 1;
      local_68 = local_68 + 0x20;
      iVar12 = iVar12 + 1;
    } while (iVar12 < *(int *)(unaff_ESI + 0x10));
  }
  return;
}

