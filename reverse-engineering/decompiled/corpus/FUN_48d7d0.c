/* Ghidra analysis pseudocode, not original source.
 * ev_966db37b3c76367cdd19664fe0d1b84c77d56b151d5f2c268a183ca8a07fabfc
 * Entry: 0x48d7d0; label: FUN_0048d7d0
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

