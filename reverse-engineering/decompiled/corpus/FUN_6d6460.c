/* Ghidra analysis pseudocode, not original source.
 * ev_374b9498cac1f2764533d2b2425c9906eb7f8dc5d78a775ccd4080d89a8f30aa
 * Entry: 0x6d6460; label: FUN_006d6460
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d6460(undefined1 *param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  float local_c;
  undefined1 local_4;
  
  FUN_004f3bb0();
  local_c = 0.0;
  fVar1 = *(float *)(DAT_02975144 + 0x6314) * -4.0;
  fVar2 = *(float *)(DAT_02975144 + 0x6318) * -4.0;
  if (100000.0 < fVar1 * fVar1 + fVar2 * fVar2) {
    DAT_029755f0 = FUN_005be2d0(fVar1,fVar2);
    if (DAT_029755f0 - _DAT_029755ec < 0x8001) {
      if (DAT_029755f0 - _DAT_029755ec < -0x8000) {
        _DAT_029755ec = _DAT_029755ec + -0x10000;
      }
    }
    else {
      _DAT_029755ec = _DAT_029755ec + 0x10000;
    }
  }
  fVar5 = (float10)FUN_004f3bb0();
  fVar5 = (float10)FUN_005be630(0x40000000,(float)fVar5 * 4.0);
  iVar3 = DAT_029755f0;
  _DAT_029758fc = (float)((float10)1 - (float10)1 / fVar5);
  _DAT_029755ec = FUN_006e6b90();
  uVar4 = iVar3 - _DAT_029755ec;
  if ((int)uVar4 < 0x8001) {
    if ((int)uVar4 < -0x8000) {
      uVar4 = uVar4 + 0x10000;
    }
  }
  else {
    uVar4 = uVar4 - 0x10000;
  }
  if (100 < (int)((uVar4 ^ (int)uVar4 >> 0x1f) - ((int)uVar4 >> 0x1f))) {
    local_c = 0.3;
  }
  if ((byte)param_1[1] < 0x70) {
    local_c = 0.7;
  }
  if (0x90 < (byte)param_1[1]) {
    local_c = 1.0;
  }
  _DAT_029755f4 = _DAT_029755f4 + (float)((float10)(local_c - _DAT_029755f4) * extraout_ST0);
  fVar1 = _DAT_029755f4 * -(float)(&DAT_029899a0)[_DAT_029755ec + 0x4000 >> 1 & 0x7fff];
  local_4 = (undefined1)
            (int)ROUND((float)((float10)(-(float)(&DAT_029899a0)[_DAT_029755ec >> 1 & 0x7fff] *
                                        _DAT_029755f4) + extraout_ST1) * 127.5);
  *param_1 = local_4;
  local_4 = (undefined1)(int)ROUND((float)((float10)fVar1 + extraout_ST1) * 127.5);
  param_1[1] = local_4;
  return;
}

