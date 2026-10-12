/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7370; label: FUN_006b7370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

undefined4 FUN_006b7370(int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  float *pfVar2;
  int iVar3;
  double *pdVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined1 *puVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float10 fVar17;
  undefined8 uStack_48;
  undefined1 local_34 [8];
  double local_2c;
  double local_24;
  undefined8 local_1c;
  double local_14;
  int local_c;
  float *local_8;
  
  uStack_48._4_4_ = 0x6b738a;
  iVar1 = -(in_EAX * 8 + 8);
  puVar8 = &stack0xffffffc0 + iVar1;
  iVar5 = 0;
  if (3 < in_EAX + 1) {
    uVar7 = in_EAX + 1U >> 2;
    iVar5 = uVar7 * 4;
    pfVar2 = (float *)(param_1 + 8);
    pdVar4 = (double *)(local_34 + iVar1 + 4);
    do {
      pdVar4[-2] = (double)pfVar2[-2];
      uVar7 = uVar7 - 1;
      pdVar4[-1] = (double)pfVar2[-1];
      *pdVar4 = (double)*pfVar2;
      pdVar4[1] = (double)pfVar2[1];
      pfVar2 = pfVar2 + 4;
      pdVar4 = pdVar4 + 4;
    } while (uVar7 != 0);
  }
  while (iVar5 <= in_EAX) {
    iVar3 = iVar5 * 4;
    iVar5 = iVar5 + 1;
    *(double *)((int)&uStack_48 + iVar5 * 8 + iVar1) = (double)*(float *)(param_1 + iVar3);
  }
  if (in_EAX < 1) {
    return 0;
  }
  iVar5 = in_EAX * 8 + -0x10;
  local_c = iVar5;
  local_8 = (float *)(param_2 + -4 + in_EAX * 4);
LAB_006b740f:
  fVar16 = (float10)0;
  iVar3 = in_EAX + -1;
  local_24 = (double)fVar16;
  local_1c = (double)CONCAT44(iVar3,(undefined4)local_1c);
  fVar9 = (float10)iVar3;
  local_2c = (double)iVar3;
  local_14 = (double)in_EAX;
  local_c = iVar5;
  do {
    fVar17 = (float10)0;
    fVar10 = (float10)*(double *)(puVar8 + iVar5 + 0x10);
    local_1c = (double)fVar17;
    iVar3 = in_EAX;
    fVar14 = fVar17;
    fVar15 = fVar17;
    if (3 < in_EAX) {
      iVar6 = (in_EAX - 4U >> 2) + 1;
      iVar3 = in_EAX + iVar6 * -4;
      pdVar4 = (double *)(puVar8 + iVar5);
      do {
        iVar6 = iVar6 + -1;
        fVar11 = fVar15 * fVar16 + fVar10;
        fVar10 = fVar10 * fVar16 + (float10)pdVar4[1];
        fVar12 = fVar11 * fVar16 + fVar10;
        fVar10 = fVar10 * fVar16 + (float10)*pdVar4;
        fVar13 = fVar12 * fVar16 + fVar10;
        fVar10 = fVar10 * fVar16 + (float10)pdVar4[-1];
        fVar14 = (((fVar14 * fVar16 + fVar15) * fVar16 + fVar11) * fVar16 + fVar12) * fVar16 +
                 fVar13;
        fVar15 = fVar13 * fVar16 + fVar10;
        fVar10 = fVar10 * fVar16 + (float10)pdVar4[-2];
        pdVar4 = pdVar4 + -4;
      } while (iVar6 != 0);
      local_1c = (double)fVar15;
      iVar5 = local_c;
    }
    if (0 < iVar3) {
      pdVar4 = (double *)(puVar8 + iVar3 * 8 + -8);
      do {
        iVar3 = iVar3 + -1;
        fVar14 = fVar14 * fVar16 + fVar15;
        fVar15 = fVar15 * fVar16 + fVar10;
        fVar10 = fVar10 * fVar16 + (float10)*pdVar4;
        pdVar4 = pdVar4 + -1;
      } while (0 < iVar3);
      local_1c = (double)fVar15;
    }
    local_34 = (undefined1  [8])(double)((float10)local_14 * fVar10);
    if ((fVar9 * fVar15 * fVar15 - (float10)local_14 * fVar10 * fVar14) * fVar9 < fVar17) {
      return 0xffffffff;
    }
    if (fVar15 <= fVar17) {
      *(undefined4 *)((int)&uStack_48 + iVar1 + 4) = 0x6b754a;
      fVar9 = (float10)FUN_006e9530();
      fVar14 = (float10)-1e-06;
      fVar16 = (float10)local_1c - fVar9;
      if ((float10)local_1c - fVar9 <= fVar14) goto LAB_006b7560;
    }
    else {
      *(undefined4 *)((int)&uStack_48 + iVar1 + 4) = 0x6b752b;
      fVar9 = (float10)FUN_006e9530();
      fVar14 = (float10)1e-06;
      fVar16 = fVar9 + (float10)local_1c;
      if (fVar14 <= fVar9 + (float10)local_1c) {
LAB_006b7560:
        fVar14 = fVar16;
      }
    }
    fVar14 = (float10)(double)local_34 / fVar14;
    fVar16 = (float10)local_24 - fVar14;
    local_24 = (double)fVar16;
    if (fVar14 < (float10)0) {
      fVar14 = fVar14 * (float10)-1.0;
    }
    if (ABS(fVar14 / fVar16) < (float10)1e-11) break;
    fVar9 = (float10)local_2c;
  } while( true );
  *local_8 = (float)fVar16;
  iVar3 = in_EAX;
  if (3 < in_EAX) {
    iVar6 = (in_EAX - 4U >> 2) + 1;
    iVar3 = in_EAX + iVar6 * -4;
    pdVar4 = (double *)(puVar8 + iVar5);
    do {
      iVar6 = iVar6 + -1;
      fVar9 = (float10)pdVar4[2] * fVar16 + (float10)pdVar4[1];
      pdVar4[1] = (double)fVar9;
      fVar9 = fVar9 * fVar16 + (float10)*pdVar4;
      *pdVar4 = (double)fVar9;
      fVar9 = fVar9 * fVar16 + (float10)pdVar4[-1];
      pdVar4[-1] = (double)fVar9;
      pdVar4[-2] = (double)(fVar9 * fVar16 + (float10)pdVar4[-2]);
      pdVar4 = pdVar4 + -4;
      iVar5 = local_c;
    } while (iVar6 != 0);
  }
  if (0 < iVar3) {
    pdVar4 = (double *)(puVar8 + iVar3 * 8 + -8);
    do {
      iVar3 = iVar3 + -1;
      *pdVar4 = (double)((float10)pdVar4[1] * fVar16 + (float10)*pdVar4);
      pdVar4 = pdVar4 + -1;
    } while (0 < iVar3);
  }
  local_8 = local_8 + -1;
  in_EAX = in_EAX + -1;
  iVar5 = iVar5 + -8;
  puVar8 = puVar8 + 8;
  local_c = iVar5;
  if (in_EAX < 1) {
    return 0;
  }
  goto LAB_006b740f;
}

