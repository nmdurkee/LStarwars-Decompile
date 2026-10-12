/* Ghidra pseudocode, not original source.
 * ev_73151266ff1c8f163ed19691e079968d47cc326d45708775e4f70bdc31fc3cf9
 * Entry: 0x5f5380; label: FUN_005f5380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f5380(int param_1)

{
  byte bVar1;
  char cVar2;
  float fVar3;
  byte bVar4;
  uint *puVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  float *pfVar10;
  int iVar11;
  char extraout_DL;
  char cVar12;
  byte *pbVar13;
  int unaff_ESI;
  float10 fVar14;
  uint local_58;
  int local_54;
  int local_4c;
  float local_44;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  
  local_58 = 0;
  bVar4 = 0;
  *(undefined4 *)(unaff_ESI + 0x68) = 0;
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
    puVar5 = DAT_009736e0;
    *(uint *)(unaff_ESI + 0x68) = *DAT_009736e0 + 3 & 0xfffffffc;
    uVar8 = *puVar5 + 3 & 0xfffffffc;
    *puVar5 = uVar8;
    *puVar5 = uVar8 + *(int *)(unaff_ESI + 0x10) * 4;
    bVar4 = 0x40;
  }
  local_4c = 0;
  if (0 < *(int *)(unaff_ESI + 0x10)) {
    local_54 = 0;
    do {
      bVar6 = 1;
      if ((param_1 != 0) && (*(int *)(param_1 + 0x24) != 0)) {
        uVar8 = local_58 & 0x80000007;
        if ((int)uVar8 < 0) {
          uVar8 = (uVar8 - 1 | 0xfffffff8) + 1;
        }
        bVar6 = *(byte *)(((int)local_58 >> 3) + *(int *)(param_1 + 0x24)) >> ((byte)uVar8 & 0x1f) &
                1;
      }
      bVar1 = *(byte *)(*(int *)(unaff_ESI + 0x48) + local_58);
      if ((*(int *)(param_1 + 0x18) == 0) || (DAT_0080ba58 == 0)) {
LAB_005f5456:
        if (bVar6 == 1) goto LAB_005f545f;
      }
      else {
        if ((bVar1 & 8) == 0) {
          bVar6 = *(byte *)(((int)local_58 >> 3) + *(int *)(param_1 + 0x1c)) >> ((byte)local_58 & 7)
                  & 1;
          goto LAB_005f5456;
        }
LAB_005f545f:
        if ((bVar1 & 1) != 0) {
          local_20 = DAT_00973718 - *(float *)(local_54 + *(int *)(unaff_ESI + 0x44));
          iVar9 = local_54 + *(int *)(unaff_ESI + 0x44);
          pfVar10 = (float *)(*(int *)(unaff_ESI + 0x28) + local_4c * 4);
          local_1c = DAT_0097371c - *(float *)(iVar9 + 4);
          local_18 = DAT_00973720 - *(float *)(iVar9 + 8);
          fVar3 = local_18 * local_18 + local_1c * local_1c + local_20 * local_20;
          if ((*pfVar10 != 0.0) && (fVar3 < *pfVar10)) {
            iVar11 = *(int *)(unaff_ESI + 0x28) + local_4c * 4;
            do {
              pfVar10 = (float *)(iVar11 + 4);
              iVar11 = iVar11 + 4;
              local_4c = local_4c + 1;
            } while (fVar3 < *pfVar10);
          }
          local_44 = *(float *)(*(int *)(unaff_ESI + 0x2c) + local_4c * 4);
          if (((bVar1 & bVar4) != 0) &&
             (pfVar10 = (float *)(*(int *)(unaff_ESI + 0xc) + local_58 * 8),
             *pfVar10 < *(float *)(*(int *)(unaff_ESI + 0xc) + 4 + local_58 * 8))) {
            local_44 = pfVar10[1];
          }
          iVar9 = FUN_005d69a0(iVar9,iVar9 + 0x10,local_44);
          if (iVar9 != 0) {
            iVar11 = FUN_005c60a0();
            cVar2 = (char)iVar9;
            cVar12 = extraout_DL;
            if (iVar11 != 0) {
              pfVar10 = (float *)(*(int *)(unaff_ESI + 0x44) + local_54);
              local_2c = *(float *)(*(int *)(unaff_ESI + 0x44) + local_54) - pfVar10[4];
              local_28 = pfVar10[1] - pfVar10[5];
              local_24 = pfVar10[2] - pfVar10[6];
              local_38 = pfVar10[4] + *pfVar10;
              local_34 = pfVar10[5] + pfVar10[1];
              local_30 = pfVar10[6] + pfVar10[2];
              cVar7 = FUN_005f27a0(&local_2c,&local_38,0);
              cVar12 = cVar2;
              if (cVar7 != '\0') goto LAB_005f567f;
            }
            if ((*(int *)(unaff_ESI + 0x68) != 0) &&
               (*(undefined4 *)(*(int *)(unaff_ESI + 0x68) + local_4c * 4) = 0x3f800000,
               (bVar1 & bVar4) != 0)) {
              fVar14 = (float10)FUN_005df7b0(fVar3,*(undefined4 *)
                                                    (*(int *)(unaff_ESI + 0xc) + local_58 * 8),
                                             *(undefined4 *)
                                              (*(int *)(unaff_ESI + 0xc) + 4 + local_58 * 8));
              *(float *)(*(int *)(unaff_ESI + 0x68) + local_4c * 4) = (float)fVar14;
              cVar12 = cVar2;
            }
            iVar11 = 0;
            iVar9 = local_4c * 0xc;
            if (0 < *(int *)(iVar9 + *(int *)(unaff_ESI + 0x14))) {
              do {
                uVar8 = *(uint *)(*(int *)(iVar9 + 4 + *(int *)(unaff_ESI + 0x14)) + iVar11 * 4);
                pbVar13 = (byte *)(*(int *)(unaff_ESI + 0x58 +
                                           (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4) +
                                  (uVar8 >> 3));
                iVar11 = iVar11 + 1;
                *pbVar13 = *pbVar13 | '\x01' << ((byte)uVar8 & 7);
                cVar12 = cVar2;
              } while (iVar11 < *(int *)(iVar9 + *(int *)(unaff_ESI + 0x14)));
            }
            pbVar13 = (byte *)(*(int *)(unaff_ESI + 0x30 +
                                       (*(uint *)(unaff_ESI + 0x74) >> 0xf & 1) * 4) +
                              (local_4c >> 2));
            *pbVar13 = *pbVar13 | cVar12 << ((byte)local_4c & 3) * '\x02';
          }
        }
      }
LAB_005f567f:
      if (*(float *)(local_4c * 4 + *(int *)(unaff_ESI + 0x28)) != 0.0) {
        iVar9 = *(int *)(unaff_ESI + 0x28) + local_4c * 4;
        do {
          pfVar10 = (float *)(iVar9 + 4);
          iVar9 = iVar9 + 4;
          local_4c = local_4c + 1;
        } while (*pfVar10 != 0.0);
      }
      local_54 = local_54 + 0x20;
      local_4c = local_4c + 1;
      local_58 = local_58 + 1;
    } while (local_4c < *(int *)(unaff_ESI + 0x10));
  }
  return;
}

