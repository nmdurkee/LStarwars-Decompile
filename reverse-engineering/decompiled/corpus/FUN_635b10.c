/* Ghidra analysis pseudocode, not original source.
 * ev_4ddc17d0b5ae2dc444590ce1384da883f11f3d0f2dd8037fed9dcc825d4bbeec
 * Entry: 0x635b10; label: FUN_00635b10
 */

void FUN_00635b10(int param_1,uint *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  char cVar10;
  undefined4 *puVar11;
  char *pcVar12;
  float fVar13;
  int iVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  float *pfVar18;
  float *pfVar19;
  char cVar20;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  float10 fVar21;
  float10 extraout_ST1_00;
  float local_14;
  float local_10;
  float local_c;
  
  puVar15 = param_2;
  iVar14 = param_1;
  local_10 = 3.4028235e+38;
  local_c = -3.4028235e+38;
  puVar11 = (undefined4 *)*param_2;
  local_14 = -3.4028235e+38;
  *param_2 = (uint)(puVar11 + 10);
  param_2 = (uint *)0x7f7fffff;
  *puVar11 = 0;
  puVar11[1] = 0;
  puVar11[2] = 0;
  puVar11[3] = 0;
  puVar11[4] = 0;
  puVar11[5] = 0;
  puVar11[6] = 0;
  puVar11[7] = 0;
  puVar11[8] = 0;
  pfVar18 = (float *)(param_1 + 4);
  puVar11[9] = 0;
  cVar10 = *(char *)(param_1 + 0x5c);
  pfVar19 = pfVar18;
  while (cVar10 != '\0') {
    fVar2 = *pfVar19 - pfVar19[0x10];
    if (local_10 < fVar2) {
      fVar2 = local_10;
    }
    fVar3 = *pfVar19 + pfVar19[0x10];
    if (fVar3 < local_c) {
      fVar3 = local_c;
    }
    fVar4 = pfVar19[2] - pfVar19[0x10];
    if ((float)param_2 < fVar4) {
      fVar4 = (float)param_2;
    }
    fVar5 = pfVar19[2] + pfVar19[0x10];
    if (fVar5 < local_14) {
      fVar5 = local_14;
    }
    cVar10 = *(char *)(pfVar19 + 0x39);
    pfVar19 = pfVar19 + 0x23;
    local_10 = fVar2;
    local_c = fVar3;
    local_14 = fVar5;
    param_2 = (uint *)fVar4;
  }
  if ((local_10 <= local_c) && ((float)param_2 <= local_14)) {
    puVar11[6] = -local_10;
    puVar11[7] = -(float)param_2;
    local_c = local_c - local_10;
    local_14 = local_14 - (float)param_2;
    if (local_c < 0.0 == (local_c == 0.0)) {
      if (local_14 < 0.0 != (local_14 == 0.0)) {
        return;
      }
      if (local_c <= local_14) {
        puVar11[4] = 0x10;
        iVar16 = FUN_006e6b90();
        iVar16 = iVar16 + 1;
        if (0x10 < iVar16) {
          iVar16 = 0x10;
        }
        puVar11[3] = iVar16;
        fVar21 = extraout_ST0_00 / extraout_ST1_00;
      }
      else {
        puVar11[3] = 0x10;
        iVar16 = FUN_006e6b90();
        iVar16 = iVar16 + 1;
        if (0x10 < iVar16) {
          iVar16 = 0x10;
        }
        puVar11[4] = iVar16;
        fVar21 = extraout_ST1 / extraout_ST0;
      }
      puVar11[5] = (float)fVar21;
      puVar11[8] = *puVar15 + 3 & 0xfffffffc;
      uVar17 = *puVar15 + 3 & 0xfffffffc;
      *puVar15 = uVar17;
      *puVar15 = uVar17 + puVar11[4] * puVar11[3] * 4;
      param_2 = (uint *)0x0;
      if (0 < (int)puVar11[4]) {
        do {
          iVar16 = (int)param_2 + 1;
          fVar2 = (float)puVar11[5];
          param_1 = 0;
          fVar3 = (float)puVar11[7];
          fVar4 = (float)puVar11[5];
          fVar5 = (float)puVar11[7];
          if (0 < (int)puVar11[3]) {
            do {
              fVar13 = (float)param_1;
              *(uint *)(puVar11[8] + (puVar11[3] * (int)param_2 + param_1) * 4) = *puVar15;
              *puVar15 = *puVar15 + 1;
              pcVar12 = *(char **)(puVar11[8] + (puVar11[3] * (int)param_2 + param_1) * 4);
              *pcVar12 = '\0';
              param_1 = param_1 + 1;
              fVar6 = (float)puVar11[5];
              cVar20 = '\0';
              fVar7 = (float)puVar11[6];
              fVar8 = (float)puVar11[5];
              fVar9 = (float)puVar11[6];
              cVar10 = *(char *)(iVar14 + 0x5c);
              pfVar19 = pfVar18;
              while (cVar10 != '\0') {
                if ((cVar10 == '\x05') ||
                   ((((fVar13 / fVar6 - fVar7 <= *pfVar19 + pfVar19[0x10] &&
                      (*pfVar19 - pfVar19[0x10] <= (float)param_1 / fVar8 - fVar9)) &&
                     ((float)(int)param_2 / fVar2 - fVar3 <= pfVar19[2] + pfVar19[0x10])) &&
                    (pfVar19[2] - pfVar19[0x10] <= (float)iVar16 / fVar4 - fVar5)))) {
                  *pcVar12 = *pcVar12 + '\x01';
                  pcVar12[*pcVar12] = cVar20;
                  *puVar15 = *puVar15 + 1;
                }
                pfVar1 = pfVar19 + 0x39;
                pfVar19 = pfVar19 + 0x23;
                cVar20 = cVar20 + '\x01';
                cVar10 = *(char *)pfVar1;
              }
            } while (param_1 < (int)puVar11[3]);
          }
          param_2 = (uint *)iVar16;
        } while (iVar16 < (int)puVar11[4]);
      }
      *puVar11 = 1;
      return;
    }
  }
  return;
}

