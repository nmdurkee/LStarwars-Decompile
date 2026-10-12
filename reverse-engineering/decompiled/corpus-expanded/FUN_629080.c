/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x629080; label: FUN_00629080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00629080(int param_1,float param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  bool bVar13;
  bool bVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  float10 extraout_ST0;
  float10 fVar18;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar19;
  
  FUN_00627230(param_1);
  if ((param_3 != 0) && (param_4 == 0)) {
    bVar7 = false;
    bVar5 = false;
    if ((param_1 == 0) ||
       ((((iVar8 = *(int *)(param_1 + 8), iVar8 == 0 || (*(code **)(iVar8 + 0x38) == (code *)0x0))
         || ((*(byte *)(iVar8 + 0x11) & 2) != 0)) ||
        ((*(int *)(param_3 + 0x70) == 0 ||
         (iVar8 = (**(code **)(iVar8 + 0x38))
                            (param_1,iVar8,*(int *)(param_3 + 0x70),*(undefined4 *)(param_3 + 0x78))
         , iVar8 == 0)))))) {
      uVar1 = *(uint *)(param_1 + 0x38);
      if ((int)(uVar1 << 0x1e) < 0) {
        uVar12 = 0x2000;
        uVar9 = 0x8000;
      }
      else {
        uVar12 = 0x4000;
        uVar9 = 0x1000;
      }
      bVar13 = (*(uint *)(param_3 + 0x78) & uVar9) != 0;
      fVar15 = (float10)0.33333334;
      if (bVar13) {
        _DAT_029130d8 = (float)fVar15;
      }
      fVar16 = (float10)0.16666667;
      fVar17 = (float10)param_2;
      fVar18 = (float10)0;
      if ((((uVar9 & *(uint *)(param_3 + 0x70)) != 0) && (fVar18 < (float10)_DAT_029130d8)) &&
         (_DAT_029130d8 = (float)((float10)_DAT_029130d8 - fVar17), (float10)_DAT_029130d8 <= fVar18
         )) {
        bVar13 = true;
        _DAT_029130d8 = (float)fVar16;
      }
      fVar19 = fVar16;
      if (((uVar1 & 4) == 0) && (-1 < (int)(uVar1 << 0x1e))) {
        if (((*(uint *)(param_3 + 0x70) & 0x8000) != 0) && ((uVar1 & 1) == 0)) {
          fVar15 = fVar18;
          fVar19 = fVar17;
          iVar8 = FUN_006e6b90();
          if (iVar8 < 1) {
            iVar8 = 1;
          }
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) - iVar8;
          fVar18 = extraout_ST1;
          fVar17 = fVar15;
          fVar15 = fVar16;
        }
        if (((*(uint *)(param_3 + 0x70) & 0x2000) != 0) && ((uVar1 & 1) == 0)) {
          fVar16 = fVar17;
          fVar15 = fVar19;
          iVar8 = FUN_006e6b90();
          if (iVar8 < 1) {
            iVar8 = 1;
          }
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + iVar8;
          fVar18 = extraout_ST0;
          fVar17 = extraout_ST1_00;
          fVar19 = fVar16;
        }
      }
      bVar14 = (*(uint *)(param_3 + 0x78) & uVar12) != 0;
      if (bVar14) {
        _DAT_029130d4 = (float)fVar15;
      }
      uVar1 = *(uint *)(param_3 + 0x70);
      if ((((uVar12 & uVar1) != 0) && (fVar18 < (float10)_DAT_029130d4)) &&
         (_DAT_029130d4 = (float)((float10)_DAT_029130d4 - fVar17), (float10)_DAT_029130d4 <= fVar18
         )) {
        _DAT_029130d4 = (float)fVar19;
        bVar14 = true;
      }
      if ((bVar13) && ((uVar1 & 1) != 0)) {
        bVar5 = true;
      }
      if ((bVar14) && ((uVar1 & 1) != 0)) {
        bVar6 = true;
        bVar7 = true;
      }
      else {
        bVar6 = false;
      }
      if ((!bVar13) || (bVar4 = true, (uVar1 & 2) == 0)) {
        bVar4 = false;
      }
      if (((bVar14) && ((uVar1 & 2) != 0)) && (*(int **)(param_1 + 0x10) != (int *)0x0)) {
        piVar10 = *(int **)(param_1 + 0xc);
        iVar8 = 1;
        if (piVar10 != (int *)0x0) {
          do {
            if (piVar10 == *(int **)(param_1 + 0x10)) break;
            piVar10 = (int *)*piVar10;
            iVar8 = iVar8 + 1;
          } while (piVar10 != (int *)0x0);
          if (iVar8 == 0) {
            return 0;
          }
        }
        while (**(int **)(param_1 + 8) != 0) {
          iVar8 = iVar8 + -1;
          *(int *)(param_1 + 8) = **(int **)(param_1 + 8);
          if (iVar8 == 0) {
            return 0;
          }
        }
      }
      else if ((bVar4) && (bVar6 = bVar7, *(undefined4 **)(param_1 + 0x10) != (undefined4 *)0x0)) {
        iVar8 = 1;
        for (puVar2 = *(undefined4 **)(param_1 + 0xc);
            (puVar2 != (undefined4 *)0x0 && (puVar2 != *(undefined4 **)(param_1 + 0x10)));
            puVar2 = (undefined4 *)*puVar2) {
          iVar8 = iVar8 + 1;
        }
        *(undefined4 **)(param_1 + 8) = *(undefined4 **)(param_1 + 0xc);
        if (iVar8 != 0) {
          while (iVar3 = *(int *)(*(int *)(param_1 + 8) + 4), iVar3 != 0) {
            iVar8 = iVar8 + -1;
            *(int *)(param_1 + 8) = iVar3;
            *(int *)(param_1 + 0xc) = iVar3;
            if (iVar8 == 0) {
              return 0;
            }
          }
        }
      }
      else if ((bVar13) &&
              ((*(int *)(param_1 + 8) != 0 && (*(int *)(*(int *)(param_1 + 8) + 4) != 0)))) {
        while( true ) {
          if (*(int *)(param_1 + 8) == *(int *)(param_1 + 0xc)) {
            *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(*(int *)(param_1 + 8) + 4);
          }
          iVar8 = *(int *)(*(int *)(param_1 + 8) + 4);
          iVar3 = *(int *)(iVar8 + 8);
          while (iVar3 == 0x12) {
            iVar8 = *(int *)(iVar8 + 4);
            iVar3 = *(int *)(iVar8 + 8);
          }
          *(int *)(param_1 + 8) = iVar8;
          if (*(int *)(iVar8 + 4) == 0) break;
          if (!bVar5) {
            return 0;
          }
        }
      }
      else if ((bVar14) &&
              ((*(int **)(param_1 + 8) != (int *)0x0 && (**(int **)(param_1 + 8) != 0)))) {
        while( true ) {
          piVar10 = (int *)**(int **)(param_1 + 8);
          iVar8 = piVar10[2];
          while (iVar8 == 0x12) {
            piVar10 = (int *)*piVar10;
            iVar8 = piVar10[2];
          }
          *(int **)(param_1 + 8) = piVar10;
          if (*piVar10 == 0) break;
          if (!bVar6) {
            return 0;
          }
        }
        if (bVar6) {
          piVar11 = *(int **)(param_1 + 0xc);
          iVar8 = 1;
          if (piVar11 != (int *)0x0) {
            do {
              if (piVar11 == *(int **)(param_1 + 0x10)) break;
              piVar11 = (int *)*piVar11;
              iVar8 = iVar8 + 1;
            } while (piVar11 != (int *)0x0);
          }
          *(int **)(param_1 + 0xc) = piVar10;
          if (iVar8 != 0) {
            while (iVar3 = *(int *)(*(int *)(param_1 + 0xc) + 4), iVar3 != 0) {
              iVar8 = iVar8 + -1;
              *(int *)(param_1 + 0xc) = iVar3;
              if (iVar8 == 0) {
                return 0;
              }
            }
          }
        }
      }
      else {
        FUN_00629030(param_1,param_3);
      }
    }
  }
  return 0;
}

