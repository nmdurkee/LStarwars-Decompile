/* Ghidra pseudocode, not original source.
 * ev_ba3680c91cc7668ea4367646649a520903a061e5f40eaeec700e4023a7d0b71b
 * Entry: 0x412bd0; label: FUN_00412bd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00412bd0(int param_1,int param_2,int param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int in_EAX;
  int iVar16;
  float *pfVar17;
  int *in_ECX;
  int iVar18;
  int iVar19;
  int iVar20;
  
  if ((*(char *)(param_1 + 1) != -1) && (param_2 == 5)) {
    iVar18 = *(char *)(param_1 + 1) * 0x13c + *in_ECX;
    pfVar17 = *(float **)(*(int *)(iVar18 + 4) + 8);
    fVar1 = *pfVar17;
    fVar2 = pfVar17[1];
    fVar3 = pfVar17[2];
    pfVar17 = *(float **)(*(int *)(iVar18 + 8) + 8);
    fVar4 = pfVar17[1];
    fVar5 = *pfVar17;
    fVar6 = pfVar17[2];
    pfVar17 = *(float **)(*(int *)(iVar18 + 0xc) + 8);
    fVar7 = *pfVar17;
    fVar8 = pfVar17[1];
    fVar9 = pfVar17[2];
    pfVar17 = *(float **)(*(int *)(iVar18 + 0x10) + 8);
    fVar10 = *pfVar17;
    fVar11 = pfVar17[1];
    fVar12 = pfVar17[2];
    fVar13 = ((fVar7 + fVar5) - fVar1) - fVar10;
    fVar14 = ((fVar8 + fVar4) - fVar2) - fVar11;
    fVar15 = ((fVar9 + fVar6) - fVar3) - fVar12;
    FUN_005c0240(fVar14 * fVar14 + fVar13 * fVar13 + fVar15 * fVar15);
    fVar10 = ((fVar5 + fVar1) - fVar7) - fVar10;
    fVar11 = ((fVar4 + fVar2) - fVar8) - fVar11;
    fVar12 = ((fVar6 + fVar3) - fVar9) - fVar12;
    FUN_005c0240(fVar12 * fVar12 + fVar11 * fVar11 + fVar10 * fVar10);
    iVar16 = (int)*(short *)(param_1 + 2) - (param_3 >> 1) * in_EAX;
    iVar19 = in_EAX * param_3 + iVar16;
    if (iVar16 < iVar19) {
      iVar20 = iVar16 * 0xc;
      iVar19 = iVar19 - iVar16;
      do {
        iVar16 = *(int *)(*(int *)(iVar18 + 4) + 8);
        fVar1 = *(float *)(iVar16 + iVar20);
        fVar2 = *(float *)(iVar16 + 4 + iVar20);
        fVar3 = *(float *)(iVar16 + iVar20 + 8);
        iVar16 = *(int *)(*(int *)(iVar18 + 8) + 8);
        fVar4 = *(float *)(iVar16 + 4 + iVar20);
        pfVar17 = (float *)(iVar16 + iVar20);
        fVar5 = *pfVar17;
        fVar6 = pfVar17[2];
        pfVar17 = (float *)(*(int *)(*(int *)(iVar18 + 0xc) + 8) + iVar20);
        fVar7 = *pfVar17;
        fVar8 = pfVar17[1];
        fVar9 = pfVar17[2];
        iVar16 = *(int *)(*(int *)(iVar18 + 0x10) + 8);
        fVar10 = *(float *)(iVar16 + iVar20);
        fVar11 = *(float *)(iVar16 + 4 + iVar20);
        fVar12 = *(float *)(iVar16 + iVar20 + 8);
        fVar13 = ((fVar7 + fVar5) - fVar1) - fVar10;
        fVar14 = ((fVar8 + fVar4) - fVar2) - fVar11;
        fVar15 = ((fVar9 + fVar6) - fVar3) - fVar12;
        FUN_005c0240(fVar15 * fVar15 + fVar14 * fVar14 + fVar13 * fVar13);
        fVar10 = ((fVar5 + fVar1) - fVar7) - fVar10;
        fVar11 = ((fVar4 + fVar2) - fVar8) - fVar11;
        fVar12 = ((fVar6 + fVar3) - fVar9) - fVar12;
        FUN_005c0240(fVar12 * fVar12 + fVar11 * fVar11 + fVar10 * fVar10);
        iVar20 = iVar20 + 0xc;
        iVar19 = iVar19 + -1;
      } while (iVar19 != 0);
    }
  }
  return;
}

