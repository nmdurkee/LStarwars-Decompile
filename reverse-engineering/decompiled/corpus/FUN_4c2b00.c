/* Ghidra analysis pseudocode, not original source.
 * ev_d6cfc7f984a94bc477afc350e10de4c03e30e64e3e924293972bd20ad72e1aa6
 * Entry: 0x4c2b00; label: FUN_004c2b00
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c2b00(undefined4 *param_1,float *param_2,int param_3)

{
  float fVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_c;
  
  if (_DAT_008800e4 < 0.0 == (_DAT_008800e4 == 0.0)) {
    fVar3 = 1.0 - _DAT_008800e4 * 8.0;
    iVar4 = FUN_006e6b90();
    fVar1 = (float)(extraout_ST0 -
                   ((float10)(float)(&DAT_029899a0)[iVar4 >> 1 & 0x7fff] + extraout_ST0) *
                   (float10)0.5);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    param_2[3] = DAT_0088042c + fVar1 * (DAT_00880420 - DAT_0088042c);
    param_2[4] = DAT_00880430 + fVar1 * (DAT_00880424 - DAT_00880430);
    param_2[5] = DAT_00880434 + fVar1 * (DAT_00880428 - DAT_00880434);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    param_2[6] = DAT_00880438 + fVar1 * (DAT_0088042c - DAT_00880438);
    param_2[7] = DAT_0088043c + fVar1 * (DAT_00880430 - DAT_0088043c);
    param_2[8] = DAT_00880440 + fVar1 * (DAT_00880434 - DAT_00880440);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    param_2[9] = DAT_00880444 + fVar1 * (DAT_00880438 - DAT_00880444);
    param_2[10] = DAT_00880448 + fVar1 * (DAT_0088043c - DAT_00880448);
    param_2[0xb] = DAT_0088044c + fVar1 * (DAT_00880440 - DAT_0088044c);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    param_2[0xc] = DAT_00880450 + fVar1 * (DAT_00880444 - DAT_00880450);
    param_2[0xd] = DAT_00880454 + fVar1 * (DAT_00880448 - DAT_00880454);
    param_2[0xe] = DAT_00880458 + fVar1 * (DAT_0088044c - DAT_00880458);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    param_2[0xf] = DAT_0088045c + fVar1 * (DAT_00880450 - DAT_0088045c);
    param_2[0x10] = DAT_00880460 + fVar1 * (DAT_00880454 - DAT_00880460);
    param_2[0x11] = DAT_00880464 + fVar1 * (DAT_00880458 - DAT_00880464);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    param_2[0x12] = DAT_00880468 + fVar1 * (DAT_0088045c - DAT_00880468);
    param_2[0x13] = DAT_0088046c + fVar1 * (DAT_00880460 - DAT_0088046c);
    param_2[0x14] = DAT_00880470 + fVar1 * (DAT_00880464 - DAT_00880470);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    _DAT_008801cc = _DAT_008801bc + fVar1 * (_DAT_0087c4dc - _DAT_008801bc);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    _DAT_0087bb70 = fVar1 * (_DAT_008801bc - _DAT_0087c4dc) + _DAT_0087c4dc;
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    _DAT_00880414 = _DAT_0087bbb8 + fVar1 * (_DAT_008800a4 - _DAT_0087bbb8);
    local_c = fVar1;
    if (1.0 <= fVar1) {
      local_c = 1.0;
    }
    if (0.0 <= local_c) {
      if (1.0 <= fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = (float)extraout_ST1;
    }
    _DAT_00880418 = fVar1 * (_DAT_0087bbb8 - _DAT_008800a4) + _DAT_008800a4;
    _DAT_0087bd7c = 1.0 - fVar3;
    _DAT_0087bd94 = fVar3;
    return 0;
  }
  uVar2 = param_1[1];
  param_1[1] = param_1[2];
  *param_1 = uVar2;
  uVar2 = param_1[3];
  param_1[3] = param_1[4];
  param_1[2] = uVar2;
  uVar2 = param_1[5];
  param_1[5] = param_1[6];
  param_1[4] = uVar2;
  param_1[6] = param_1[6] + 1;
  if (param_3 <= (int)param_1[6]) {
    param_1[6] = 0;
  }
  _DAT_0087bb70 = _DAT_0087c4dc;
  _DAT_008800e4 = (float)0;
  *param_2 = DAT_00880420;
  _DAT_008801cc = _DAT_008801bc;
  _DAT_0087bed0 = _DAT_0087bb70;
  param_2[1] = DAT_00880424;
  param_2[2] = DAT_00880428;
  _DAT_00880410 = _DAT_008800a4;
  param_2[3] = DAT_0088042c;
  param_2[4] = DAT_00880430;
  param_2[5] = DAT_00880434;
  param_2[6] = DAT_00880438;
  param_2[7] = DAT_0088043c;
  param_2[8] = DAT_00880440;
  param_2[9] = DAT_00880444;
  param_2[10] = DAT_00880448;
  param_2[0xb] = DAT_0088044c;
  param_2[0xc] = DAT_00880450;
  param_2[0xd] = DAT_00880454;
  param_2[0xe] = DAT_00880458;
  param_2[0xf] = DAT_0088045c;
  param_2[0x10] = DAT_00880460;
  param_2[0x11] = DAT_00880464;
  param_2[0x12] = DAT_00880468;
  param_2[0x13] = DAT_0088046c;
  param_2[0x14] = DAT_00880470;
  DAT_0087bb84 = 0;
  _DAT_00880414 = _DAT_0087bbb8;
  _DAT_00880418 = _DAT_00880410;
  _DAT_0087bd7c = 0.0;
  _DAT_0087bd80 = 0x3ecccccd;
  _DAT_0087bd84 = 0x3f4ccccd;
  _DAT_0087bd8c = 0x3f4ccccd;
  _DAT_0087bd90 = 0x3ecccccd;
  _DAT_0087bd94 = 0.0;
  return 1;
}

