/* Ghidra analysis pseudocode, not original source.
 * ev_fde8b55f02fe7b53f1a00cfd799b40252fec9b79621de4d26dfdea385167393c
 * Entry: 0x4fd050; label: FUN_004fd050
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004fd050(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  float10 fVar6;
  DWORD local_1c;
  int local_10;
  int local_c;
  uint local_8;
  int local_4;
  
  iVar3 = FUN_004feb50();
  if (0.0 < _DAT_008004e8) {
    _DAT_008004e8 = _DAT_008004e8 - _DAT_0297dbfc;
    DAT_00917848 = 0x14;
    FUN_005d4290(1);
    iVar4 = FUN_006de050();
    if (iVar4 != 0) {
      uVar5 = FUN_006de050();
      FUN_004f3f50(0xffffffff,uVar5);
    }
    FUN_005f3950();
  }
  FUN_00601330(_DAT_0297dbfc);
  FUN_005d34a0(_DAT_0297dbfc);
  FUN_005ddc80(DAT_0297dc38,_DAT_0297dbfc);
  FUN_005c6100();
  FUN_005de1a0();
  FUN_006df300();
  if (DAT_00827610 == 0) {
    if (DAT_02975c24 == 0) {
      FUN_00698fa0();
      do {
        if (DAT_00827610 != 0) break;
        Sleep(10);
        iVar4 = FUN_006dd390();
      } while (iVar4 != 0);
      FUN_006d3420();
      FUN_004ffb20(&DAT_0297dbec,&DAT_0297dbf0);
      if (DAT_0297dbf0 < 0) {
        FUN_004ef790();
      }
      FUN_00696b00();
    }
    else {
      Sleep(1);
      FUN_006dd390();
    }
  }
  else {
    FUN_006dd390();
    FUN_006d3420();
  }
  FUN_004f4c80();
  FUN_005f3d60(0xffffffff);
  FUN_0060b5b0(1,DAT_0091ef04);
  FUN_005de1b0();
  FUN_006df310();
  FUN_004ffb20(&local_8,&local_4);
  local_c = local_4;
  if (local_4 < 0) {
    local_c = FUN_004ef790();
  }
  if (local_8 < DAT_0297dbec) {
    local_c = (local_c - DAT_0297dbf0) + -1;
  }
  else {
    local_c = local_c - DAT_0297dbf0;
  }
  local_10 = local_8 - DAT_0297dbec;
  fVar6 = (float10)FUN_004f3c30(&local_10);
  _DAT_0297dbfc = (float)fVar6;
  _DAT_029803c0 = _DAT_029803c0 + _DAT_0297dbfc;
  iVar4 = FUN_006df270();
  fVar1 = (float)iVar4;
  if (iVar4 < 0) {
    fVar1 = fVar1 + 4.2949673e+09;
  }
  if (85.0 <= fVar1) {
    iVar4 = FUN_006df270();
    fVar1 = (float)iVar4;
    if (iVar4 < 0) {
      fVar1 = fVar1 + 4.2949673e+09;
    }
  }
  else {
    fVar1 = 85.0;
  }
  iVar4 = FUN_006df270();
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + 4.2949673e+09;
  }
  if (fVar2 <= 85.0) {
    iVar4 = FUN_006df270();
    fVar2 = (float)iVar4;
    if (iVar4 < 0) {
      fVar2 = fVar2 + 4.2949673e+09;
    }
  }
  else {
    fVar2 = 85.0;
  }
  DAT_008004e4 = 0x14;
  if (1.1 <= _DAT_0297dbfc / (1.0 / fVar2)) {
    DAT_008004e4 = 1;
  }
  if (_DAT_0297dbfc < 1.0 / fVar1) {
    local_1c = (DWORD)(longlong)ROUND((1.0 / fVar1 - _DAT_0297dbfc) * 1000.0);
    Sleep(local_1c);
    FUN_004ffb20(&local_8,&local_4);
    if (local_4 < 0) {
      local_4 = FUN_004ef790();
    }
    if (local_8 < DAT_0297dbec) {
      local_c = (local_4 - DAT_0297dbf0) + -1;
    }
    else {
      local_c = local_4 - DAT_0297dbf0;
    }
    local_10 = local_8 - DAT_0297dbec;
    fVar6 = (float10)FUN_004f3c30(&local_10);
    _DAT_0297dbfc = (float)fVar6;
  }
  FUN_004ffb20(&DAT_0297dbec,&DAT_0297dbf0);
  if (DAT_0297dbf0 < 0) {
    FUN_004ef790();
  }
  FUN_004ffb20(&DAT_0297dbf4,&DAT_0297dbf8);
  if (DAT_0297dbf8 < 0) {
    FUN_004ef790();
  }
  FUN_004ff0c0(DAT_008004e4);
  FUN_004fb130();
  DAT_0297dc00 = DAT_0297dc00 + 1;
  if (_DAT_0297dc04 != 0.0) {
    _DAT_0297dbfc = _DAT_0297dc04;
  }
  DAT_0297dbe4 = DAT_0297dbe4 + -1;
  if ((DAT_0091ef1c == 0) && (iVar3 != 0)) {
    DAT_0091ef1c = 1;
    FUN_004f91f0();
    FUN_004feb60();
    DAT_0091ef1c = 0;
  }
  _DAT_0297dc48 = 0;
  return (float10)_DAT_0297dbfc;
}

