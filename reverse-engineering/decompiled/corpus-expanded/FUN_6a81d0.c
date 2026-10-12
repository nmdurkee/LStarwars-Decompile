/* Ghidra pseudocode, not original source.
 * ev_9aa9869018ecc20f1423d5d8d6944da52d455e1cf8e536d99f80bf4f445d14b5
 * Entry: 0x6a81d0; label: FUN_006a81d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void * FUN_006a81d0(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  void *pvVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int *piVar15;
  double dVar16;
  int local_1c;
  float local_14;
  float local_10;
  int *local_8;
  
  iVar13 = 0;
  if ((param_1[3] != 1) && (param_1[3] != 2)) {
    return (void *)0x0;
  }
  uVar1 = param_1[4];
  dVar16 = (double)(uVar1 & 0x1fffff);
  if ((int)uVar1 < 0) {
    dVar16 = -dVar16;
  }
  dVar16 = _ldexp(dVar16,((int)uVar1 >> 0x15 & 0x3ffU) - 0x314);
  fVar5 = (float)dVar16;
  uVar1 = param_1[5];
  dVar16 = (double)(uVar1 & 0x1fffff);
  if ((int)uVar1 < 0) {
    dVar16 = -dVar16;
  }
  dVar16 = _ldexp(dVar16,((int)uVar1 >> 0x15 & 0x3ffU) - 0x314);
  fVar6 = (float)dVar16;
  pvVar8 = _calloc(*param_1 * param_2,4);
  if (param_1[3] == 1) {
    iVar10 = FUN_006a8150(param_1);
    iVar2 = param_1[1];
    local_1c = 0;
    if (0 < iVar2) {
      do {
        if ((param_3 == 0) || (*(int *)(param_1[2] + local_1c * 4) != 0)) {
          local_10 = 0.0;
          iVar9 = *param_1;
          iVar11 = 0;
          iVar14 = 1;
          if (3 < iVar9) {
            iVar3 = param_1[8];
            iVar4 = param_1[7];
            do {
              fVar7 = ABS((float)*(int *)(iVar3 + ((local_1c / iVar14) % iVar10) * 4)) * fVar6 +
                      fVar5 + local_10;
              if (iVar4 != 0) {
                local_10 = fVar7;
              }
              iVar12 = iVar13;
              if (param_3 != 0) {
                iVar12 = *(int *)(param_3 + iVar13 * 4);
              }
              *(float *)((int)pvVar8 + (iVar12 * iVar9 + iVar11) * 4) = fVar7;
              fVar7 = ABS((float)*(int *)(iVar3 + ((local_1c / (iVar14 * iVar10)) % iVar10) * 4)) *
                      fVar6 + fVar5 + local_10;
              if (iVar4 != 0) {
                local_10 = fVar7;
              }
              iVar12 = iVar13;
              if (param_3 != 0) {
                iVar12 = *(int *)(param_3 + iVar13 * 4);
              }
              iVar14 = iVar14 * iVar10 * iVar10;
              *(float *)((int)pvVar8 + (iVar12 * iVar9 + iVar11) * 4 + 4) = fVar7;
              fVar7 = ABS((float)*(int *)(iVar3 + ((local_1c / iVar14) % iVar10) * 4)) * fVar6 +
                      fVar5 + local_10;
              if (iVar4 != 0) {
                local_10 = fVar7;
              }
              iVar12 = iVar13;
              if (param_3 != 0) {
                iVar12 = *(int *)(param_3 + iVar13 * 4);
              }
              iVar14 = iVar14 * iVar10;
              *(float *)((int)pvVar8 + (iVar12 * iVar9 + iVar11) * 4 + 8) = fVar7;
              fVar7 = ABS((float)*(int *)(iVar3 + ((local_1c / iVar14) % iVar10) * 4)) * fVar6 +
                      fVar5 + local_10;
              if (iVar4 != 0) {
                local_10 = fVar7;
              }
              iVar12 = iVar13;
              if (param_3 != 0) {
                iVar12 = *(int *)(param_3 + iVar13 * 4);
              }
              iVar14 = iVar14 * iVar10;
              iVar12 = iVar12 * iVar9 + iVar11;
              iVar11 = iVar11 + 4;
              *(float *)((int)pvVar8 + iVar12 * 4 + 0xc) = fVar7;
            } while (iVar11 < iVar9 + -3);
          }
          if (iVar11 < iVar9) {
            iVar3 = param_1[8];
            iVar4 = param_1[7];
            do {
              fVar7 = ABS((float)*(int *)(iVar3 + ((local_1c / iVar14) % iVar10) * 4)) * fVar6 +
                      fVar5 + local_10;
              if (iVar4 != 0) {
                local_10 = fVar7;
              }
              iVar12 = iVar13;
              if (param_3 != 0) {
                iVar12 = *(int *)(param_3 + iVar13 * 4);
              }
              iVar14 = iVar14 * iVar10;
              iVar12 = iVar12 * iVar9 + iVar11;
              iVar11 = iVar11 + 1;
              *(float *)((int)pvVar8 + iVar12 * 4) = fVar7;
            } while (iVar11 < iVar9);
          }
          iVar13 = iVar13 + 1;
        }
        local_1c = local_1c + 1;
      } while (local_1c < iVar2);
    }
  }
  else if (param_1[3] == 2) {
    iVar2 = param_1[1];
    local_1c = 0;
    if (0 < iVar2) {
      do {
        if ((param_3 == 0) || (*(int *)(param_1[2] + local_1c * 4) != 0)) {
          iVar10 = *param_1;
          local_14 = 0.0;
          iVar9 = 0;
          if (3 < iVar10) {
            iVar11 = param_1[7];
            piVar15 = (int *)(param_1[8] + 8 + iVar10 * local_1c * 4);
            local_8 = (int *)(param_1[8] + 4 + iVar10 * local_1c * 4);
            do {
              fVar7 = ABS((float)piVar15[-2]) * fVar6 + fVar5 + local_14;
              if (iVar11 != 0) {
                local_14 = fVar7;
              }
              iVar14 = iVar13;
              if (param_3 != 0) {
                iVar14 = *(int *)(param_3 + iVar13 * 4);
              }
              *(float *)((int)pvVar8 + (iVar14 * iVar10 + iVar9) * 4) = fVar7;
              fVar7 = ABS((float)*local_8) * fVar6 + fVar5 + local_14;
              if (iVar11 != 0) {
                local_14 = fVar7;
              }
              iVar14 = iVar13;
              if (param_3 != 0) {
                iVar14 = *(int *)(param_3 + iVar13 * 4);
              }
              *(float *)((int)pvVar8 + (iVar14 * iVar10 + iVar9) * 4 + 4) = fVar7;
              fVar7 = ABS((float)*piVar15) * fVar6 + fVar5 + local_14;
              if (iVar11 != 0) {
                local_14 = fVar7;
              }
              iVar14 = iVar13;
              if (param_3 != 0) {
                iVar14 = *(int *)(param_3 + iVar13 * 4);
              }
              *(float *)((int)pvVar8 + (iVar14 * iVar10 + iVar9) * 4 + 8) = fVar7;
              fVar7 = ABS((float)piVar15[1]) * fVar6 + fVar5 + local_14;
              if (iVar11 != 0) {
                local_14 = fVar7;
              }
              iVar14 = iVar13;
              if (param_3 != 0) {
                iVar14 = *(int *)(param_3 + iVar13 * 4);
              }
              local_8 = local_8 + 4;
              *(float *)((int)pvVar8 + (iVar14 * iVar10 + iVar9) * 4 + 0xc) = fVar7;
              iVar9 = iVar9 + 4;
              piVar15 = piVar15 + 4;
            } while (iVar9 < iVar10 + -3);
          }
          if (iVar9 < iVar10) {
            local_8 = (int *)(param_1[8] + (iVar10 * local_1c + iVar9) * 4);
            do {
              fVar7 = ABS((float)*local_8) * fVar6 + fVar5 + local_14;
              if (param_1[7] != 0) {
                local_14 = fVar7;
              }
              iVar11 = iVar13;
              if (param_3 != 0) {
                iVar11 = *(int *)(param_3 + iVar13 * 4);
              }
              local_8 = local_8 + 1;
              iVar11 = iVar11 * iVar10 + iVar9;
              iVar9 = iVar9 + 1;
              *(float *)((int)pvVar8 + iVar11 * 4) = fVar7;
            } while (iVar9 < iVar10);
          }
          iVar13 = iVar13 + 1;
        }
        local_1c = local_1c + 1;
      } while (local_1c < iVar2);
      return pvVar8;
    }
  }
  return pvVar8;
}

