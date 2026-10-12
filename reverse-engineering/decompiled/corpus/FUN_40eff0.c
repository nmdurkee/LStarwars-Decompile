/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x40eff0; label: FUN_0040eff0
 */

void FUN_0040eff0(float *param_1,float *param_2)

{
  int iVar1;
  float *pfVar2;
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
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float *pfVar28;
  float *pfVar29;
  float10 extraout_ST0;
  float local_80;
  float local_7c;
  float local_78;
  undefined4 local_74;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  
  fVar24 = param_1[0x100];
  fVar27 = (float)FUN_006e6b90();
  fVar3 = (float)(extraout_ST0 - (float10)(int)fVar27);
  if ((int)fVar27 < 1) {
    local_80 = *param_1 - param_1[4];
    local_7c = param_1[1] - param_1[5];
    local_78 = param_1[2] - param_1[6];
    FUN_005b3b30(&local_80,&local_80);
    fVar27 = 0.0;
    local_74 = 0x3f800000;
    pfVar29 = &local_30;
    local_30 = *param_1 + local_80 * 10.0;
    local_2c = param_1[1] + local_7c * 10.0;
    local_28 = param_1[2] + local_78 * 10.0;
    local_24 = param_1[3];
  }
  else {
    if ((int)fVar24 + -1 < (int)fVar27) {
      fVar27 = fVar24;
    }
    pfVar29 = param_1 + (int)fVar27 * 4 + -4;
  }
  pfVar2 = param_1 + (int)fVar27 * 4;
  if ((int)fVar27 < (int)param_1[0x100] + -2) {
    pfVar28 = param_1 + ((int)fVar27 + 2) * 4;
  }
  else {
    fVar24 = param_1[0x100];
    iVar1 = (int)fVar24 + -2;
    local_80 = param_1[(int)fVar24 * 4 + -4] - param_1[iVar1 * 4];
    local_7c = param_1[(int)fVar24 * 4 + -3] - param_1[iVar1 * 4 + 1];
    local_78 = param_1[(int)fVar24 * 4 + -2] - param_1[iVar1 * 4 + 2];
    FUN_005b3b30(&local_80,&local_80);
    fVar24 = param_1[0x100];
    local_20 = param_1[(int)fVar24 * 4 + -4] + local_80 * 10.0;
    local_1c = param_1[(int)fVar24 * 4 + -3] + local_7c * 10.0;
    local_18 = param_1[(int)fVar24 * 4 + -2] + local_78 * 10.0;
    pfVar28 = &local_20;
    local_14 = param_1[(int)fVar24 * 4 + -1];
  }
  fVar24 = pfVar2[1];
  fVar27 = pfVar2[2];
  fVar4 = pfVar2[5];
  fVar5 = pfVar29[1];
  fVar6 = pfVar2[6];
  fVar7 = pfVar29[2];
  fVar8 = pfVar29[1];
  fVar9 = pfVar29[2];
  fVar10 = pfVar2[1];
  fVar11 = pfVar2[2];
  fVar12 = pfVar2[5];
  fVar13 = pfVar2[6];
  fVar14 = pfVar28[1];
  fVar15 = pfVar28[2];
  fVar26 = fVar3 * fVar3;
  fVar16 = pfVar2[1];
  fVar17 = pfVar2[5];
  fVar18 = pfVar2[2];
  fVar19 = pfVar2[6];
  fVar20 = pfVar29[1];
  fVar21 = pfVar29[2];
  fVar22 = pfVar28[1];
  fVar23 = pfVar28[2];
  fVar25 = fVar26 * fVar3;
  *param_2 = (fVar3 * (pfVar2[4] - *pfVar29) + *pfVar2 + *pfVar2 +
              fVar26 * ((pfVar2[4] * 4.0 + ((*pfVar29 + *pfVar29) - *pfVar2 * 5.0)) - *pfVar28) +
             fVar25 * (((*pfVar2 - pfVar2[4]) * 3.0 - *pfVar29) + *pfVar28)) * 0.5;
  param_2[1] = ((fVar4 - fVar5) * fVar3 + fVar24 + fVar24 +
                ((fVar12 * 4.0 + ((fVar8 + fVar8) - fVar10 * 5.0)) - fVar14) * fVar26 +
               (fVar22 + ((fVar16 - fVar17) * 3.0 - fVar20)) * fVar25) * 0.5;
  param_2[2] = ((fVar6 - fVar7) * fVar3 + fVar27 + fVar27 +
                fVar26 * ((fVar13 * 4.0 + ((fVar9 + fVar9) - fVar11 * 5.0)) - fVar15) +
               fVar25 * (((fVar18 - fVar19) * 3.0 - fVar21) + fVar23)) * 0.5;
  param_2[3] = (pfVar2[7] - pfVar2[3]) * fVar3 + pfVar2[3];
  return;
}

