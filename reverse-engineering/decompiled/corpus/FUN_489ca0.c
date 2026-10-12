/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x489ca0; label: FUN_00489ca0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00489ca0(void)

{
  undefined4 uVar1;
  int iVar2;
  float10 fVar3;
  
  iVar2 = FUN_005cfac0(&DAT_0087aad8);
  if (iVar2 != 0) {
    iVar2 = FUN_00574e20();
    if (((iVar2 == -1) || (iVar2 == 0)) || (iVar2 == 1)) {
      uVar1 = 0x3f800000;
    }
    else {
      uVar1 = 0;
    }
    fVar3 = (float10)FUN_0054fad0(_DAT_0087aa50,uVar1,_DAT_00925018 + _DAT_00925018);
    _DAT_0087aa50 = (float)fVar3;
  }
  fVar3 = (float10)FUN_0054fad0(_DAT_0087aa58,0x3f800000,_DAT_00925018 + _DAT_00925018);
  _DAT_0087aa58 = (float)fVar3;
  iVar2 = FUN_00574e20();
  if ((iVar2 == 0) && (4.0 < _DAT_0092505c != (_DAT_0092505c == 4.0))) {
    DAT_0087a9d0 = 0x3f800000;
  }
  else {
    DAT_0087a9d0 = 0;
  }
  fVar3 = (float10)FUN_0054fad0(DAT_0087a9cc,DAT_0087a9d0,_DAT_00925018 + _DAT_00925018);
  DAT_0087a9cc = (float)fVar3;
  return;
}

