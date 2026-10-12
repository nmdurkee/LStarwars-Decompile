/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x564cd0; label: FUN_00564cd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00564cd0(int param_1)

{
  float fVar1;
  float *pfVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_8;
  
  pfVar2 = DAT_00950620;
  if ((*(int *)(param_1 + 0x2ab4) == 0) ||
     (((DAT_00951be0 != 0 && (DAT_00951be8 != 0)) && ((*(byte *)(DAT_00951be8 + 0x50) & 4) != 0))))
  {
    pfVar3 = (float *)0x0;
  }
  else {
    pfVar3 = (float *)FUN_00638020(*(int *)(param_1 + 0x2ab4),DAT_00925164 + 0x30);
  }
  iVar5 = DAT_00950668;
  fVar1 = 0.0;
  DAT_00950620 = pfVar3;
  if (DAT_00950668 == 0) {
    if (pfVar3 != pfVar2) {
      _DAT_00950624 = 3.0;
      puVar6 = &DAT_009506b8;
      puVar7 = &DAT_00950628;
      _DAT_0095061c = fVar1;
      for (iVar4 = 0xe; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      goto LAB_00564d55;
    }
LAB_00564e10:
    if ((pfVar3 != (float *)0x0) &&
       (_DAT_00950664 = (float)*(byte *)(pfVar3 + 6) / 10.0, _DAT_00950664 != 0.0))
    goto LAB_00564e45;
  }
  else {
LAB_00564d55:
    if (pfVar3 != (float *)0x0) {
      DAT_00950680 = (float)*(byte *)((int)pfVar3 + 0xb);
      DAT_00950684 = (float)*(byte *)((int)pfVar3 + 10);
      _DAT_00950688 = (float)*(byte *)((int)pfVar3 + 9);
      _DAT_0095068c = (float)*(byte *)(pfVar3 + 2);
      _DAT_00950690 = *pfVar3;
      _DAT_00950694 = pfVar3[1];
      _DAT_00950698 = pfVar3[0xb];
      _DAT_009506a0 = (float)(int)pfVar3[3];
      _DAT_009506a4 = (float)*(byte *)((int)pfVar3 + 0x13);
      _DAT_009506a8 = (float)*(byte *)((int)pfVar3 + 0x12);
      _DAT_009506ac = (float)*(byte *)((int)pfVar3 + 0x11);
      _DAT_009506b0 = (float)*(byte *)(pfVar3 + 4);
      goto LAB_00564e10;
    }
    _DAT_00950690 = 5.0;
    _DAT_00950694 = 20.0;
    DAT_00950680 = fVar1;
    DAT_00950684 = fVar1;
    _DAT_00950688 = fVar1;
    _DAT_0095068c = fVar1;
    _DAT_00950698 = fVar1;
    _DAT_009506a0 = fVar1;
    _DAT_009506a4 = fVar1;
    _DAT_009506a8 = fVar1;
    _DAT_009506ac = fVar1;
    _DAT_009506b0 = fVar1;
  }
  _DAT_00950664 = _DAT_00802e20;
LAB_00564e45:
  if (iVar5 == 0) {
    if ((_DAT_0095061c < _DAT_00950624) &&
       (_DAT_0095061c = _DAT_00925018 + _DAT_0095061c, _DAT_00950624 < _DAT_0095061c)) {
      _DAT_0095061c = _DAT_00950624;
    }
    if (_DAT_00950624 < _DAT_0095061c == (_DAT_00950624 == _DAT_0095061c)) {
      iVar5 = FUN_006e6b90();
      fVar1 = 1.0 - ((float)(&DAT_029899a0)[iVar5 >> 1 & 0x7fff] + 1.0) * 0.5;
      DAT_009506b8 = fVar1 * (DAT_00950680 - DAT_00950628) + DAT_00950628;
      DAT_009506bc = DAT_0095062c + fVar1 * (DAT_00950684 - DAT_0095062c);
      _DAT_009506c0 = _DAT_00950630 + fVar1 * (_DAT_00950688 - _DAT_00950630);
      _DAT_009506c4 = _DAT_00950634 + fVar1 * (_DAT_0095068c - _DAT_00950634);
      _DAT_009506c8 = _DAT_00950638 + fVar1 * (_DAT_00950690 - _DAT_00950638);
      _DAT_009506cc = _DAT_0095063c + fVar1 * (_DAT_00950694 - _DAT_0095063c);
      _DAT_009506d0 = _DAT_00950640 + fVar1 * (_DAT_00950698 - _DAT_00950640);
      _DAT_009506d8 = _DAT_00950648 + fVar1 * (_DAT_009506a0 - _DAT_00950648);
      _DAT_009506dc = _DAT_0095064c + fVar1 * (_DAT_009506a4 - _DAT_0095064c);
      _DAT_009506e0 = _DAT_00950650 + fVar1 * (_DAT_009506a8 - _DAT_00950650);
      _DAT_009506e4 = _DAT_00950654 + fVar1 * (_DAT_009506ac - _DAT_00950654);
      _DAT_009506e8 = _DAT_00950658 + (_DAT_009506b0 - _DAT_00950658) * fVar1;
    }
    else {
      puVar6 = &DAT_00950680;
      puVar7 = &DAT_009506b8;
      for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
  }
  else {
    puVar6 = &DAT_00950680;
    puVar7 = &DAT_009506b8;
    _DAT_0095061c = fVar1;
    _DAT_00950624 = fVar1;
    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  DAT_00950668 = 0;
  local_8 = (int)(longlong)ROUND(DAT_009506b8);
  iVar5 = local_8 * 0x100;
  local_8 = (int)(longlong)ROUND(DAT_009506bc);
  iVar5 = iVar5 + local_8;
  local_8 = (int)(longlong)ROUND(_DAT_009506c0);
  iVar5 = iVar5 * 0x100 + local_8;
  local_8 = (int)(longlong)ROUND(_DAT_009506c4);
  _DAT_009506d4 = iVar5 * 0x100 + local_8;
  local_8 = (int)(longlong)ROUND(_DAT_009506dc);
  iVar5 = local_8 * 0x100;
  local_8 = (int)(longlong)ROUND(_DAT_009506e0);
  iVar5 = iVar5 + local_8;
  local_8 = (int)(longlong)ROUND(_DAT_009506e4);
  iVar5 = iVar5 * 0x100 + local_8;
  local_8 = (int)(longlong)ROUND(_DAT_009506e8);
  _DAT_009506ec = iVar5 * 0x100 + local_8;
  return;
}

