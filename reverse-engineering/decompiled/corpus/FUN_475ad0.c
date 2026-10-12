/* Ghidra analysis pseudocode, not original source.
 * ev_89b7b842136f36149785ae3176f422ef77993aed8671c7148cbe0781c54fcb17
 * Entry: 0x475ad0; label: FUN_00475ad0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00475ad0(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  if (((DAT_0093b324 != 0) && (param_1 == 0)) && (iVar1 = FUN_0055f1a0(), iVar1 == 0)) {
    fVar3 = (float10)FUN_0054fad0(_DAT_007fa1ac,0x3f800000,_DAT_00925018);
    _DAT_007fa1ac = (float)fVar3;
    iVar1 = FUN_006e6b90();
    iVar2 = FUN_006e6b90();
    if (iVar2 == iVar1) {
      return;
    }
    FUN_00547930(0x35,0,0,0);
    return;
  }
  _DAT_007fa1ac = 1.0;
  return;
}

