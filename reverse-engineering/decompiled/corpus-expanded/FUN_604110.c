/* Ghidra pseudocode, not original source.
 * ev_4377ad99129b2c218cc07e3c8fdbc7bfca14166fd1a7528fd51d788f3b01d532
 * Entry: 0x604110; label: FUN_00604110
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00604110(float *param_1,float *param_2,float *param_3,int param_4,uint *param_5)

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
  int iVar14;
  float fVar15;
  float fVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  float fVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  float fVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  uint uVar35;
  uint uVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  float fVar40;
  
  iVar14 = param_4 + 3 >> 2;
  if (0 < iVar14) {
    fVar1 = *param_3;
    fVar2 = param_3[1];
    fVar3 = param_3[2];
    fVar4 = param_3[4];
    fVar5 = param_3[5];
    fVar6 = param_3[6];
    fVar7 = param_3[8];
    fVar8 = param_3[9];
    fVar9 = param_3[10];
    fVar10 = param_3[0xc];
    fVar11 = param_3[0xd];
    fVar12 = param_3[0xe];
    do {
      fVar15 = param_2[1];
      fVar16 = param_2[2];
      fVar23 = param_2[3];
      fVar30 = param_2[5];
      fVar37 = param_2[6];
      fVar38 = param_2[7];
      fVar39 = param_2[9];
      fVar40 = param_2[10];
      fVar13 = param_2[0xb];
      *param_1 = fVar10 + fVar1 * *param_2 + fVar4 * param_2[4] + fVar7 * param_2[8];
      param_1[1] = fVar10 + fVar1 * fVar15 + fVar4 * fVar30 + fVar7 * fVar39;
      param_1[2] = fVar10 + fVar1 * fVar16 + fVar4 * fVar37 + fVar7 * fVar40;
      param_1[3] = fVar10 + fVar1 * fVar23 + fVar4 * fVar38 + fVar7 * fVar13;
      fVar15 = param_2[1];
      fVar16 = param_2[2];
      fVar23 = param_2[3];
      fVar30 = param_2[5];
      fVar37 = param_2[6];
      fVar38 = param_2[7];
      fVar39 = param_2[9];
      fVar40 = param_2[10];
      fVar13 = param_2[0xb];
      param_1[4] = fVar11 + fVar2 * *param_2 + fVar5 * param_2[4] + fVar8 * param_2[8];
      param_1[5] = fVar11 + fVar2 * fVar15 + fVar5 * fVar30 + fVar8 * fVar39;
      param_1[6] = fVar11 + fVar2 * fVar16 + fVar5 * fVar37 + fVar8 * fVar40;
      param_1[7] = fVar11 + fVar2 * fVar23 + fVar5 * fVar38 + fVar8 * fVar13;
      fVar15 = fVar12 + fVar3 * *param_2 + fVar6 * param_2[4] + fVar9 * param_2[8];
      fVar16 = fVar12 + fVar3 * param_2[1] + fVar6 * param_2[5] + fVar9 * param_2[9];
      fVar23 = fVar12 + fVar3 * param_2[2] + fVar6 * param_2[6] + fVar9 * param_2[10];
      fVar30 = fVar12 + fVar3 * param_2[3] + fVar6 * param_2[7] + fVar9 * param_2[0xb];
      param_1[8] = fVar15;
      param_1[9] = fVar16;
      param_1[10] = fVar23;
      param_1[0xb] = fVar30;
      uVar17 = -(uint)(fVar16 < DAT_00973730) & uRam0080e874;
      uVar24 = -(uint)(fVar23 < DAT_00973730) & uRam0080e878;
      uVar31 = -(uint)(fVar30 < DAT_00973730) & uRam0080e87c;
      uVar18 = -(uint)(_DAT_0080e8f4 < fVar16) & uRam0080e884;
      uVar25 = -(uint)(_DAT_0080e8f8 < fVar23) & uRam0080e888;
      uVar32 = -(uint)(_DAT_0080e8fc < fVar30) & uRam0080e88c;
      fVar37 = DAT_00966378 * fVar15 * _DAT_0080e8d0;
      fVar38 = DAT_00966378 * fVar16 * fRam0080e8d4;
      fVar39 = DAT_00966378 * fVar23 * fRam0080e8d8;
      fVar40 = DAT_00966378 * fVar30 * fRam0080e8dc;
      uVar19 = -(uint)(param_1[1] < fVar38) & uRam0080e894;
      uVar26 = -(uint)(param_1[2] < fVar39) & uRam0080e898;
      uVar33 = -(uint)(param_1[3] < fVar40) & uRam0080e89c;
      uVar20 = -(uint)(fVar38 * fRam0080e8d4 < param_1[1]) & uRam0080e8a4;
      uVar27 = -(uint)(fVar39 * fRam0080e8d8 < param_1[2]) & uRam0080e8a8;
      uVar34 = -(uint)(fVar40 * fRam0080e8dc < param_1[3]) & uRam0080e8ac;
      fVar38 = DAT_0097313c * fVar15 * _DAT_0080e8d0;
      fVar16 = DAT_0097313c * fVar16 * fRam0080e8d4;
      fVar23 = DAT_0097313c * fVar23 * fRam0080e8d8;
      fVar30 = DAT_0097313c * fVar30 * fRam0080e8dc;
      uVar21 = -(uint)(param_1[5] < fVar16) & uRam0080e8b4;
      uVar28 = -(uint)(param_1[6] < fVar23) & uRam0080e8b8;
      uVar35 = -(uint)(param_1[7] < fVar30) & uRam0080e8bc;
      uVar22 = -(uint)(fVar16 * fRam0080e8d4 < param_1[5]) & uRam0080e8c4;
      uVar29 = -(uint)(fVar23 * fRam0080e8d8 < param_1[6]) & uRam0080e8c8;
      uVar36 = -(uint)(fVar30 * fRam0080e8dc < param_1[7]) & uRam0080e8cc;
      *param_5 = -(uint)(fVar15 < DAT_00973730) & _DAT_0080e870 |
                 -(uint)(_DAT_0080e8f0 < fVar15) & _DAT_0080e880 |
                 -(uint)(*param_1 < fVar37) & _DAT_0080e890 |
                 -(uint)(fVar37 * _DAT_0080e8d0 < *param_1) & _DAT_0080e8a0 |
                 -(uint)(param_1[4] < fVar38) & _DAT_0080e8b0 |
                 -(uint)(fVar38 * _DAT_0080e8d0 < param_1[4]) & _DAT_0080e8c0;
      param_5[1] = uVar17 | uVar18 | uVar19 | uVar20 | uVar21 | uVar22;
      param_5[2] = uVar24 | uVar25 | uVar26 | uVar27 | uVar28 | uVar29;
      param_5[3] = uVar31 | uVar32 | uVar33 | uVar34 | uVar35 | uVar36;
      param_5 = param_5 + 4;
      param_2 = param_2 + 0xc;
      iVar14 = iVar14 + -1;
      param_1 = param_1 + 0xc;
    } while (iVar14 != 0);
  }
  return;
}

