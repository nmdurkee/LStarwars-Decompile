/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x41f660; label: FUN_0041f660
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041f660(void)

{
  float fVar1;
  float fVar2;
  
  fVar1 = _DAT_0097374c;
  fVar2 = _DAT_007f17a8;
  if (DAT_00951288 != 0) {
    fVar2 = _DAT_007f17ac;
  }
  if (_DAT_0097374c < fVar2) {
    fVar2 = _DAT_0097374c;
  }
  _DAT_0097374c = fVar2;
  FUN_00603cc0(&DAT_009736e8);
  FUN_0041f480(0);
  _DAT_0097374c = fVar1;
  FUN_00603cc0(&DAT_009736e8);
  return;
}

