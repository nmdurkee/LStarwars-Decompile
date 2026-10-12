/* Ghidra pseudocode, not original source.
 * ev_6614b6c0ec400e98b17ca3318749993ac398f4a5e7c651bffc9aeb30b42772d2
 * Entry: 0x509d00; label: FUN_00509d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_00509d00(uint param_1,uint param_2,uint param_3,uint param_4,float param_5,uint param_6,
            uint param_7,uint param_8,uint param_9)

{
  float fVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  float fVar11;
  int iVar12;
  float *pfVar13;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar14;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar15;
  float10 fVar16;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  int local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  int local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  float local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  iVar6 = DAT_00800944;
  local_38 = 0;
  DAT_00921d34 = 0;
  if (DAT_00921d44 == 0) {
    return 0;
  }
  iVar12 = DAT_00800944 * 0xe0;
  pfVar13 = (float *)(&DAT_00921440 + DAT_00800944 * 0x38);
  if ((DAT_00921d64 == 0) ||
     ((_DAT_00921d5c < 1.0 &&
      (_DAT_00921d5c = param_5 + param_5 + _DAT_00921d5c, 1.0 < _DAT_00921d5c)))) {
    _DAT_00921d5c = 1.0;
  }
  FUN_006e6b90();
  _DAT_00921d60 = FUN_006e6b90();
  fVar14 = (float10)0;
  if ((float10)_DAT_00921d6c <= fVar14) {
    _DAT_00921d70 = (float)fVar14;
    fVar15 = extraout_ST0;
    fVar16 = extraout_ST1;
  }
  else {
    fVar16 = extraout_ST0;
    iVar10 = FUN_006e6b90();
    DAT_00921d68 = DAT_00921d68 + iVar10;
    _DAT_00921d70 = ((float)(&DAT_029899a0)[DAT_00921d68 >> 1 & 0x7fff] + 1.0) * 0.5;
    fVar14 = extraout_ST0_00;
    fVar15 = extraout_ST1_00;
  }
  DAT_00800940 = -1;
  if (fVar14 < (float10)_DAT_00921da4) {
    _DAT_00921da4 = (float)((float10)_DAT_00921da4 - fVar16);
  }
  if ((&DAT_00921454)[iVar6 * 0x70] == -1) {
    return 0;
  }
  local_54 = param_1;
  if ((param_1 & 0xf000) == 0) {
    local_54 = param_1 | param_3;
  }
  if ((param_2 & 0xf000) == 0) {
    param_2 = param_2 | param_4;
  }
  if (fVar15 < (float10)0.5) {
    local_54 = 0;
    param_2 = 0;
  }
  local_4c = param_2 & 0x1000;
  local_50 = param_2 & 0x4000;
  local_34 = param_2 & 0x8000;
  local_30 = param_2 & 0x2000;
  local_48 = local_54 & 0x1000;
  if (DAT_00921d94 != 0) {
    if (local_48 == 0) {
      DAT_00921d94 = 0;
    }
    else {
      local_48 = 0;
    }
  }
  local_44 = local_54 & 0x4000;
  if (DAT_00921d98 != 0) {
    if (local_44 == 0) {
      DAT_00921d98 = 0;
    }
    else {
      local_44 = 0;
    }
  }
  local_40 = local_54 & 0x8000;
  if (DAT_00921d9c != 0) {
    if (local_40 == 0) {
      DAT_00921d9c = 0;
    }
    else {
      local_40 = 0;
    }
  }
  local_3c = local_54 & 0x2000;
  if (DAT_00921da0 != 0) {
    if (local_3c == 0) {
      DAT_00921da0 = 0;
    }
    else {
      local_3c = 0;
    }
  }
  local_20 = param_2 & 4;
  local_1c = param_2 & 8;
  local_2c = param_2 & param_6;
  local_28 = param_2 & param_7;
  local_10 = param_2 & param_8;
  local_4 = param_2 & param_9;
  if (fVar14 == (float10)(float)(&DAT_00921444)[iVar6 * 0x38]) {
    local_28 = 0;
    local_2c = 0;
  }
  if ((local_4c != 0) && (local_50 != 0)) {
    local_50 = 0;
    local_4c = 0;
  }
  local_c = local_4c;
  local_8 = local_50;
  if ((local_34 != 0) && (local_30 != 0)) {
    local_30 = 0;
    local_34 = 0;
  }
  if ((local_48 != 0) && (local_44 != 0)) {
    local_44 = 0;
    local_48 = 0;
  }
  if ((local_40 != 0) && (local_3c != 0)) {
    local_3c = 0;
    local_40 = 0;
  }
  if ((local_20 != 0) && (local_1c != 0)) {
    local_1c = 0;
    local_20 = 0;
  }
  if (*(int *)(iVar12 + 0x921518) != 0) {
    local_4c = 0;
    local_50 = 0;
    local_10 = 0;
    local_2c = 0;
    local_28 = 0;
  }
  FUN_00509ca0(&local_48,&local_4c,iVar12 + 0x921460,iVar12 + 0x921470,0x3dcccccd,(float)fVar16);
  FUN_00509ca0(&local_44,&local_50,iVar12 + 0x921464,iVar12 + 0x921471,0x3dcccccd,param_5);
  FUN_00509ca0(&local_40,&local_34,iVar12 + 0x921468,iVar12 + 0x921472,0x3dcccccd,param_5);
  FUN_00509ca0(&local_3c,&local_30,iVar12 + 0x92146c,iVar12 + 0x921473,0x3dcccccd,param_5);
  sVar9 = (&DAT_00921452)[iVar6 * 0x70];
  sVar3 = (&DAT_0092144e)[iVar6 * 0x70];
  fVar11 = (float)(((int)(short)(&DAT_00921450)[iVar6 * 0x70] -
                   (int)(short)(&DAT_0092144c)[iVar6 * 0x70]) + 1);
  iVar10 = ((int)sVar9 - (int)sVar3) + 1;
  local_18 = iVar10;
  if ((float)(&DAT_00921458)[iVar6 * 0x38] < (float)(&DAT_0092145c)[iVar6 * 0x38]) {
    local_14 = (float)(&DAT_00921458)[iVar6 * 0x38] + param_5;
    local_28 = 0;
    local_2c = 0;
    (&DAT_00921458)[iVar6 * 0x38] = local_14;
    if ((float)(&DAT_0092145c)[iVar6 * 0x38] < local_14 !=
        ((float)(&DAT_0092145c)[iVar6 * 0x38] == local_14)) {
      cVar2 = (&DAT_00921457)[iVar12];
      (&DAT_00921458)[iVar6 * 0x38] = (&DAT_0092145c)[iVar6 * 0x38];
      if (cVar2 != -1) {
        FUN_00509830((int)cVar2,0xffffffff,0xffffffff);
      }
    }
    goto LAB_0050a2e5;
  }
  sVar8 = (&DAT_0092144a)[iVar6 * 0x70];
  local_38 = (int)sVar8;
  local_24 = 0;
  if (sVar8 < sVar3) {
    (&DAT_0092144a)[iVar6 * 0x70] = sVar3;
    local_24 = 1;
  }
  else if (sVar9 < sVar8) {
    (&DAT_0092144a)[iVar6 * 0x70] = sVar9;
    local_24 = 1;
  }
  else if ((&DAT_00800ac0)[(short)(&DAT_00921454)[iVar6 * 0x70] * 0x1c] == '\0') {
    if ((local_50 == 0) || (sVar9 <= sVar8)) {
      if ((local_4c == 0) || (sVar8 <= sVar3)) goto LAB_0050a22f;
      sVar8 = sVar8 + -1;
    }
    else {
      sVar8 = sVar8 + 1;
    }
    (&DAT_0092144a)[iVar6 * 0x70] = sVar8;
  }
  else if (local_50 == 0) {
    if ((local_4c != 0) && ((&DAT_0092144a)[iVar6 * 0x70] = sVar8 + -1, (short)(sVar8 + -1) < sVar3)
       ) {
      (&DAT_0092144a)[iVar6 * 0x70] = sVar9;
    }
  }
  else {
    (&DAT_0092144a)[iVar6 * 0x70] = sVar8 + 1;
    if (sVar9 < (short)(sVar8 + 1)) {
      (&DAT_0092144a)[iVar6 * 0x70] = sVar3;
    }
  }
LAB_0050a22f:
  iVar7 = DAT_00800950;
  sVar3 = (&DAT_0092144a)[iVar6 * 0x70];
  if ((sVar3 != local_38) && ((&DAT_00921444)[iVar6 * 0x38] = 0, local_24 == 0)) {
    DAT_00800940 = iVar7;
  }
  iVar4 = (&DAT_0092151c)[iVar6 * 0x38];
  local_14 = fVar11;
  if (((iVar4 != 1) && ((iVar4 != 2 || (sVar3 != 0)))) && ((iVar4 != 3 || (sVar3 == sVar9))))
  goto LAB_0050a2e5;
  sVar9 = (&DAT_00921448)[iVar6 * 0x70];
  sVar3 = (&DAT_0092144c)[iVar6 * 0x70];
  local_38 = (int)sVar9;
  if (sVar9 < sVar3) {
    (&DAT_00921448)[iVar6 * 0x70] = sVar3;
  }
  else if ((short)(&DAT_00921450)[iVar6 * 0x70] < sVar9) {
    (&DAT_00921448)[iVar6 * 0x70] = (&DAT_00921450)[iVar6 * 0x70];
  }
  if ((local_30 == 0) ||
     ((short)(&DAT_00921450)[iVar6 * 0x70] <= (short)(&DAT_00921448)[iVar6 * 0x70])) {
    if ((local_34 != 0) && (sVar3 < (short)(&DAT_00921448)[iVar6 * 0x70])) {
      sVar9 = (&DAT_00921448)[iVar6 * 0x70] + -1;
      goto LAB_0050a2c6;
    }
  }
  else {
    sVar9 = (&DAT_00921448)[iVar6 * 0x70] + 1;
LAB_0050a2c6:
    (&DAT_00921448)[iVar6 * 0x70] = sVar9;
  }
  if ((short)(&DAT_00921448)[iVar6 * 0x70] != local_38) {
    DAT_00800940 = iVar7;
    (&DAT_00921444)[iVar6 * 0x38] = 0;
  }
LAB_0050a2e5:
  fVar1 = *pfVar13;
  sVar9 = (&DAT_0092144a)[iVar6 * 0x70];
  *(int *)(iVar12 + 0x921478) = (int)(short)(&DAT_00921448)[iVar6 * 0x70];
  *pfVar13 = param_5 + fVar1;
  *(int *)(iVar12 + 0x921474) = (int)sVar9;
  fVar1 = (float)(&DAT_00921444)[iVar6 * 0x38];
  *(uint *)(iVar12 + 0x921494) = local_c;
  *(uint *)(iVar12 + 0x921480) = local_54;
  (&DAT_00921444)[iVar6 * 0x38] = param_5 + fVar1;
  *(uint *)(iVar12 + 0x9214a0) = local_30;
  *(uint *)(iVar12 + 0x92149c) = local_34;
  *(uint *)(iVar12 + 0x9214ac) = local_48;
  *(int *)(iVar12 + 0x92147c) = local_38;
  *(uint *)(iVar12 + 0x9214a8) = local_28;
  *(uint *)(iVar12 + 0x9214b8) = local_3c;
  *(uint *)(iVar12 + 0x921498) = local_8;
  *(uint *)(iVar12 + 0x9214b4) = local_40;
  *(uint *)(iVar12 + 0x9214c4) = local_20;
  sVar9 = (&DAT_00921454)[iVar6 * 0x70];
  *(uint *)(iVar12 + 0x9214a4) = local_2c;
  *(uint *)(iVar12 + 0x9214c0) = local_4;
  *(uint *)(iVar12 + 0x9214b0) = local_44;
  pcVar5 = (code *)(&PTR_FUN_00800ab4)[sVar9 * 7];
  *(uint *)(iVar12 + 0x921484) = param_2;
  *(uint *)(iVar12 + 0x9214bc) = local_10;
  *(int *)(iVar12 + 0x92148c) = iVar10;
  *(float *)(iVar12 + 0x921488) = fVar11;
  *(uint *)(iVar12 + 0x9214c8) = local_1c;
  if (pcVar5 != (code *)0x0) {
    (*pcVar5)(pfVar13);
  }
  if ((DAT_00800940 != -1) && (*(int *)(iVar12 + 0x921518) == 0)) {
    FUN_00681e90(DAT_00800940,0);
    DAT_00800940 = -1;
  }
  return DAT_00921d34;
}

