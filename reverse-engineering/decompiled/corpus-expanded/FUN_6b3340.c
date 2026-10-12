/* Ghidra pseudocode, not original source.
 * ev_5bc2cffe930f75cca3d7b3a74e2b00ef78f9b6b1aa332ee39fd35bfa060f9fa0
 * Entry: 0x6b3340; label: FUN_006b3340
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_006b3340(uint *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  void *pvVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  int iVar9;
  int iVar10;
  size_t sVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  float10 fVar15;
  int local_14;
  size_t local_10;
  
  piVar2 = _calloc(1,0x2c);
  iVar1 = *(int *)(param_2 + 0x10);
  iVar6 = *(int *)(*(int *)((int)param_1 + 4) + 0x1c);
  sVar11 = *(size_t *)(param_2 + 0xc);
  iVar13 = *(int *)(iVar6 + 0xb20);
  piVar2[3] = iVar13;
  piVar8 = (int *)(iVar13 + iVar1 * 0x2c);
  piVar2[4] = (int)piVar8;
  iVar1 = *piVar8;
  iVar13 = 0;
  local_14 = 0;
  local_10 = 0;
  *piVar2 = param_2;
  piVar2[1] = sVar11;
  pvVar3 = _calloc(sVar11,4);
  piVar2[5] = (int)pvVar3;
  if (0 < piVar2[1]) {
    param_1 = (uint *)(param_2 + 0x14);
    do {
      uVar4 = *param_1;
      sVar11 = 0;
      if (uVar4 != 0) {
        do {
          sVar11 = sVar11 + 1;
          uVar4 = uVar4 >> 1;
        } while (uVar4 != 0);
        if (sVar11 != 0) {
          if ((int)local_10 < (int)sVar11) {
            local_10 = sVar11;
          }
          pvVar5 = _calloc(sVar11,4);
          *(void **)((int)pvVar3 + iVar13 * 4) = pvVar5;
          iVar9 = 0;
          if (0 < (int)sVar11) {
            piVar8 = (int *)(param_2 + 0x114 + local_14 * 4);
            do {
              if ((*param_1 & 1 << ((byte)iVar9 & 0x1f)) != 0) {
                local_14 = local_14 + 1;
                *(int *)(*(int *)((int)pvVar3 + iVar13 * 4) + iVar9 * 4) =
                     *piVar8 * 0x2c + *(int *)(iVar6 + 0xb20);
                piVar8 = piVar8 + 1;
              }
              iVar9 = iVar9 + 1;
            } while (iVar9 < (int)sVar11);
          }
        }
      }
      param_1 = param_1 + 1;
      iVar13 = iVar13 + 1;
    } while (iVar13 < piVar2[1]);
  }
  fVar15 = (float10)FUN_006e92e0();
  FUN_006eafc0((double)(fVar15 + (float10)0.5));
  iVar6 = FUN_006e6b90();
  piVar2[6] = iVar6;
  piVar2[2] = local_10;
  pvVar3 = _malloc(iVar6 * 4);
  piVar2[7] = (int)pvVar3;
  iVar6 = piVar2[6];
  iVar13 = 0;
  if (0 < iVar6) {
    iVar9 = piVar2[1];
    do {
      pvVar5 = _malloc(iVar1 * 4);
      *(void **)((int)pvVar3 + iVar13 * 4) = pvVar5;
      iVar10 = 0;
      iVar12 = iVar13;
      iVar14 = iVar6;
      if (0 < iVar1) {
        do {
          iVar14 = iVar14 / iVar9;
          iVar7 = iVar12 / iVar14;
          iVar10 = iVar10 + 1;
          iVar12 = iVar12 - iVar7 * iVar14;
          *(int *)(*(int *)((int)pvVar3 + iVar13 * 4) + -4 + iVar10 * 4) = iVar7;
        } while (iVar10 < iVar1);
      }
      iVar13 = iVar13 + 1;
    } while (iVar13 < iVar6);
  }
  return piVar2;
}

