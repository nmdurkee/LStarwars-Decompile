/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5dfbd0; label: FUN_005dfbd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dfbd0(float param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float10 fVar11;
  int *local_1c;
  int local_14;
  
  _DAT_0097add0 = _DAT_0097add0 + param_1;
  FUN_004ffaa0(DAT_00973fa4);
  for (piVar6 = DAT_00973fa8; piVar6 != (int *)0x0; piVar6 = (int *)piVar6[3]) {
    iVar4 = *piVar6;
    local_14 = 0;
    if (0 < piVar6[1]) {
      do {
        iVar5 = *(int *)(*(int *)(iVar4 + 0x50) + *(int *)(piVar6[2] + local_14 * 4) * 4);
        if ((*(char *)(iVar5 + 0x7b) != '\x01') && (*(char *)(iVar5 + 0x7c) != '\x01')) {
          local_1c = (int *)(iVar5 + 0x1c0);
          iVar8 = 0;
          pfVar10 = (float *)(iVar5 + 0x1d4);
          pfVar9 = (float *)(iVar5 + 0x204);
          do {
            if (*local_1c != -1) {
              cVar3 = *(char *)(pfVar9 + -3);
              fVar1 = 0.0;
              if (cVar3 == '\x02') {
                fVar1 = *pfVar9 * param_1 + pfVar10[-1];
                pfVar10[-1] = fVar1;
                fVar11 = (float10)FUN_005b7cc0(fVar1);
                fVar1 = (float)((float10)fVar1 - fVar11);
                pfVar10[-1] = fVar1;
              }
              else if (cVar3 == '\x03') {
                iVar7 = FUN_006e6b90();
                fVar1 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] * pfVar9[-2];
              }
              else if (cVar3 == '\x04') {
                iVar7 = FUN_006e6b90();
                fVar1 = (float)(&DAT_029899a0)[0x4000 - iVar7 >> 1 & 0x7fff] * pfVar9[-2];
              }
              cVar3 = *(char *)((int)pfVar9 + -0xb);
              fVar2 = 0.0;
              if (cVar3 == '\x02') {
                fVar2 = pfVar9[1] * param_1 + *pfVar10;
                *pfVar10 = fVar2;
                fVar11 = (float10)FUN_005b7cc0(fVar2);
                fVar2 = (float)((float10)fVar2 - fVar11);
                *pfVar10 = fVar2;
              }
              else if (cVar3 == '\x03') {
                iVar7 = FUN_006e6b90();
                fVar2 = (float)(&DAT_029899a0)[iVar7 >> 1 & 0x7fff] * pfVar9[-1];
              }
              else if (cVar3 == '\x04') {
                iVar7 = FUN_006e6b90();
                fVar2 = (float)(&DAT_029899a0)[0x4000 - iVar7 >> 1 & 0x7fff] * pfVar9[-1];
              }
              FUN_00601210(iVar5,iVar8,fVar1,fVar2);
            }
            local_1c = local_1c + 1;
            iVar8 = iVar8 + 1;
            pfVar9 = pfVar9 + 5;
            pfVar10 = pfVar10 + 2;
          } while (iVar8 < 4);
        }
        local_14 = local_14 + 1;
      } while (local_14 < piVar6[1]);
    }
  }
  FUN_004ffac0(DAT_00973fa4);
  return;
}

