/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x595e00; label: FUN_00595e00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00595e00(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 extraout_ST0;
  float10 fVar7;
  float10 fVar8;
  float10 extraout_ST1;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = *param_1;
  iVar3 = FUN_0056e0f0(1);
  if (iVar3 != 0) {
    FUN_005958b0();
    return;
  }
  if (*(char *)(iVar2 + 0x28b) != '\0') {
    FUN_005954f0(iVar2 + 0x550,iVar2 + 0x574,iVar2 + 0x55c,iVar2 + 0x580,iVar2 + 0x568,iVar2 + 0x58c
                 ,iVar2 + 0x598);
    return;
  }
  local_54 = *(float *)(iVar2 + 0x61c);
  param_1 = (int *)0x3f800000;
  local_50 = *(float *)(iVar2 + 0x620);
  local_58 = 1.0;
  local_5c = 1.0;
  local_4c = *(float *)(iVar2 + 0x624);
  local_48 = *(float *)(iVar2 + 0x628);
  local_44 = *(float *)(iVar2 + 0x62c);
  local_40 = *(float *)(iVar2 + 0x630);
  local_24 = *(undefined4 *)(iVar2 + 0x64c);
  local_20 = *(undefined4 *)(iVar2 + 0x650);
  local_1c = *(undefined4 *)(iVar2 + 0x654);
  local_3c = *(float *)(iVar2 + 0x634);
  local_38 = *(float *)(iVar2 + 0x638);
  local_34 = *(float *)(iVar2 + 0x63c);
  local_18 = *(undefined4 *)(iVar2 + 0x658);
  local_14 = *(undefined4 *)(iVar2 + 0x65c);
  local_10 = *(undefined4 *)(iVar2 + 0x660);
  local_30 = *(float *)(iVar2 + 0x640);
  local_2c = *(float *)(iVar2 + 0x644);
  local_28 = *(float *)(iVar2 + 0x648);
  local_c = *(undefined4 *)(iVar2 + 0x664);
  local_8 = *(undefined4 *)(iVar2 + 0x668);
  local_4 = *(undefined4 *)(iVar2 + 0x66c);
  fVar6 = (float10)1;
  fVar4 = (float10)2.0;
  if (0.0 < *(float *)(iVar2 + 0x1018)) {
    fVar5 = (float10)(*(float *)(iVar2 + 0x1018) / 0.4);
    local_5c = (float)(fVar5 * ((float10)_DAT_0080508c - fVar6) + fVar6);
    local_58 = (float)(((float10)_DAT_00955b24 - fVar6) * fVar5 + fVar6);
    fVar5 = (float10)(float)(((float10)_DAT_00955b28 - fVar6) * fVar5 + fVar6);
    goto LAB_00596075;
  }
  if ((((DAT_00955b20 == 0) || ((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0)) ||
      (*(float *)(iVar2 + 0xd60) <= 0.0)) ||
     ((fVar4 < (float10)*(float *)(iVar2 + 0xd60) == (fVar4 == (float10)*(float *)(iVar2 + 0xd60))
      && (fVar6 = (float10)FUN_005b7d30(*(undefined4 *)(iVar2 + 0xd60),0x3ecccccd),
         fVar6 < (float10)0.20000000298023224)))) {
    if (((*(uint *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x90) & 0x8000) != 0) &&
       ((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0)) goto LAB_00596067;
    if ((DAT_00955b30 != (code *)0x0) && (iVar3 = (*DAT_00955b30)(iVar2), iVar3 != 0)) {
      iVar3 = FUN_0054fa60();
      if (iVar3 < 0x8000) {
        fVar1 = 1.0;
      }
      else {
        fVar1 = 0.25;
      }
      if ((*(byte *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x96) & 1) == 0) {
        local_5c = fVar1 * _DAT_00955b2c;
        local_58 = _DAT_00805090 * fVar1;
        fVar5 = (float10)(fVar1 * _DAT_00805094);
        fVar4 = (float10)2.0;
        fVar6 = (float10)1;
      }
      else {
        local_5c = fVar1 + fVar1;
        fVar5 = (float10)local_5c;
        fVar4 = (float10)2.0;
        fVar6 = (float10)1;
        local_58 = local_5c;
      }
      goto LAB_00596075;
    }
    fVar4 = (float10)2.0;
    fVar6 = (float10)1;
    if (*(float *)(iVar2 + 0xdd4) <= 0.0) {
      if ((((DAT_00955b1c == 0) || ((*(byte *)(iVar2 + 0x1fc) & 0x80) == 0)) ||
          (*(char *)(iVar2 + 0x107f) != '\x01')) ||
         ((*(byte *)(iVar2 + 0x107e) < 2 || (-0.5 <= *(float *)(iVar2 + 0x1018))))) {
        if ((0.0 < *(float *)(iVar2 + 0x1000)) && (*(char *)(iVar2 + 0x280) != -1)) {
          fVar6 = (float10)FUN_005b7d30(2.5 - *(float *)(iVar2 + 0x1000),0x3f000000);
          fVar1 = (float)(&DAT_029899a0)
                         [(uint)(int)ROUND((fVar6 + fVar6) * (float10)65536.0) >> 1 & 0x7fff];
          goto LAB_00596360;
        }
      }
      else {
        iVar3 = FUN_006e6b90();
        fVar6 = (float10)(float)((extraout_ST0 -
                                 (float10)(float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff]) *
                                 (float10)0.5 * (float10)0.3330000042915344);
        local_5c = (float)(fVar6 * ((float10)_DAT_0080508c - extraout_ST0) + extraout_ST0);
        local_58 = (float)(((float10)_DAT_00955b24 - extraout_ST0) * fVar6 + extraout_ST0);
        param_1 = (int *)(float)(((float10)_DAT_00955b28 - extraout_ST0) * fVar6 + extraout_ST0);
        fVar6 = extraout_ST0;
        fVar4 = extraout_ST1;
      }
      fVar5 = (float10)(float)param_1;
      goto LAB_00596075;
    }
    FUN_005b7d30(_DAT_00925064,0x3f000000);
    iVar3 = FUN_006e6b90();
    fVar1 = *(float *)(iVar2 + 0xdd4) * 0.5 * (float)(&DAT_029899a0)[iVar3 >> 1 & 0x7fff];
LAB_00596360:
    param_1 = (int *)(fVar1 + 1.0);
    local_5c = (float)param_1;
    local_58 = (float)param_1;
  }
  else if (*(char *)(iVar2 + 0x280) == '\x01') {
    local_5c = 1.7;
    local_58 = 2.0;
    param_1 = (int *)0x3fb33333;
  }
  else {
LAB_00596067:
    local_58 = 1.85;
    local_5c = 1.4;
    param_1 = (int *)0x40000000;
  }
  fVar6 = (float10)1;
  fVar4 = (float10)2.0;
  fVar5 = (float10)(float)param_1;
LAB_00596075:
  if (0.0 < *(float *)(iVar2 + 0xd6c)) {
    fVar6 = (float10)(float)((float10)*(float *)(iVar2 + 0xd6c) * (float10)-0.33399999141693115 +
                            fVar6);
    local_5c = (float)(fVar6 * (float10)local_5c);
    local_58 = (float)(fVar6 * (float10)local_58);
    fVar5 = (float10)(float)(fVar6 * fVar5);
  }
  if ((*(uint *)(*(int *)(*(int *)(iVar2 + 0x54) + 0x24) + 0x90) & 0x8000) == 0) {
    fVar6 = (float10)local_5c;
    fVar8 = (float10)local_58;
  }
  else {
    fVar7 = (float10)_DAT_00805030;
    fVar6 = (float10)(float)(fVar7 * (float10)local_5c);
    if (fVar4 < fVar6) {
      fVar6 = (float10)(float)fVar4;
    }
    fVar8 = (float10)(float)(fVar7 * (float10)local_58);
    if (fVar4 < fVar8) {
      fVar8 = (float10)(float)fVar4;
    }
    fVar5 = (float10)(float)(fVar7 * fVar5);
    if (fVar4 < fVar5) {
      fVar5 = (float10)(float)fVar4;
    }
  }
  fVar4 = (float10)1;
  if (fVar4 != fVar6) {
    local_54 = (float)((float10)local_54 * fVar6);
    local_48 = (float)((float10)local_48 * fVar6);
    local_3c = (float)((float10)local_3c * fVar6);
    local_30 = (float)((float10)local_30 * fVar6);
  }
  if (fVar4 != fVar8) {
    local_50 = (float)((float10)local_50 * fVar8);
    local_44 = (float)((float10)local_44 * fVar8);
    local_38 = (float)((float10)local_38 * fVar8);
    local_2c = (float)(fVar8 * (float10)local_2c);
  }
  if (fVar4 != fVar5) {
    local_4c = (float)((float10)local_4c * fVar5);
    local_40 = (float)((float10)local_40 * fVar5);
    local_34 = (float)((float10)local_34 * fVar5);
    local_28 = (float)(fVar5 * (float10)local_28);
  }
  FUN_00595110(&local_24,&local_3c);
  _DAT_009716e8 = local_54;
  _DAT_009716ec = local_50;
  _DAT_009716f0 = local_4c;
  FUN_005fca90(&local_54);
  return;
}

