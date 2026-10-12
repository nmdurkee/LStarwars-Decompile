/* Ghidra pseudocode, not original source.
 * ev_5eff2230042d4b302660c3ceed2c1b8d608e2d2abaeafeeac76364ea55e51798
 * Entry: 0x48d7d0; label: FUN_0048d7d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048d7d0(void)

{
  float10 fVar1;
  int local_8;
  float local_4;
  
  FUN_0059d710(0,&local_8,0);
  if (local_8 == 0) {
    DAT_0087a9d0 = 0x3f800000;
  }
  else {
    DAT_0087a9d0 = 0;
  }
  local_4 = _DAT_00925018 + _DAT_00925018;
  fVar1 = (float10)FUN_0054fad0(DAT_0087a9cc,DAT_0087a9d0,local_4);
  DAT_0087a9cc = (float)fVar1;
  return;
}

