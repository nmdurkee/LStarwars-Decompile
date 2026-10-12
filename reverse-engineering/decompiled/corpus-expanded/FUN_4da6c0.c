/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4da6c0; label: FUN_004da6c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004da6c0(float param_1)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  float10 fVar7;
  float10 extraout_ST0;
  float10 fVar8;
  float10 extraout_ST1;
  
  fVar3 = 0.0;
  fVar1 = 1.0;
  fVar4 = fVar3;
  fVar5 = fVar3;
  if (((_DAT_00950780 == 0.0) && (DAT_00855de0 == 0)) && (DAT_00951be0 == 0)) {
    if ((DAT_0093b328 == 0) &&
       (((*(int *)(PTR_DAT_00802c54 + 0x128) != DAT_0087b090 || (_DAT_0092505c < 1.0)) ||
        (6.0 <= _DAT_0092505c)))) {
      fVar1 = fVar3;
    }
    fVar7 = (float10)FUN_0054fad0(_DAT_00882a5c,fVar1,param_1 + param_1);
    _DAT_00882a5c = (float)fVar7;
    fVar3 = _DAT_00882a50;
    fVar4 = _DAT_00882a54;
    fVar5 = _DAT_00882a5c;
  }
  _DAT_00882a5c = fVar5;
  _DAT_00882a54 = fVar4;
  _DAT_00882a50 = fVar3;
  iVar6 = DAT_00882a6c;
  iVar2 = DAT_00881cc4;
  fVar7 = (float10)1;
  fVar8 = (float10)0;
  if (((DAT_0093b328 != 0) || (DAT_00882a6c == 0)) || (10.0 <= *(float *)(DAT_00882a6c + 0xb008))) {
    _DAT_00882a50 = (float)fVar8;
  }
  else {
    DAT_00881cc4 = FUN_006e6b90();
    fVar8 = extraout_ST0;
    fVar7 = extraout_ST1;
    if (((float10)_DAT_00882a50 < extraout_ST1) &&
       (_DAT_00882a50 = (float)((float10)param_1 + (float10)param_1 + (float10)_DAT_00882a50),
       extraout_ST1 < (float10)_DAT_00882a50)) {
      _DAT_00882a50 = (float)extraout_ST1;
    }
  }
  if (((0 < DAT_00881cc4) && (DAT_00881cc4 != -1)) && (DAT_00881cc4 != iVar2)) {
    FUN_00548710();
    fVar7 = (float10)1;
    fVar8 = (float10)0;
    iVar6 = DAT_00882a6c;
  }
  if ((DAT_0093b328 == 0) && (iVar6 != 0)) {
    if ((fVar8 < (float10)*(float *)(iVar6 + 0xb000)) &&
       (((float10)_DAT_00882a54 < fVar7 &&
        (_DAT_00882a54 = (float)((float10)param_1 + (float10)param_1 + (float10)_DAT_00882a54),
        fVar7 < (float10)_DAT_00882a54)))) {
      _DAT_00882a54 = (float)fVar7;
      return;
    }
    return;
  }
  return;
}

