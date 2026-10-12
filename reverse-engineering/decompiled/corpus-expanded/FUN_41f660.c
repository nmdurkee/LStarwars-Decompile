/* Ghidra pseudocode, not original source.
 * ev_12b000564e8cba1f3519ff70f1088df218803466ba65b3333f742de5377565cf
 * Entry: 0x41f660; label: FUN_0041f660
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

