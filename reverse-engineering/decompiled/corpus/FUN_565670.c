/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x565670; label: FUN_00565670
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565670(void)

{
  undefined4 uVar1;
  float10 fVar2;
  
  if (DAT_00951be0 == 0) {
    if (((DAT_008021b8 == -1) || ((char)PTR_DAT_008021b4[0x22c] != DAT_008021b8)) &&
       ((DAT_008021bc == -1 ||
        (((char)PTR_DAT_008021b4[0x22c] != DAT_008021bc || (DAT_009514e0 == 0)))))) {
      uVar1 = 0;
      goto LAB_005656bb;
    }
  }
  uVar1 = 0x3f800000;
LAB_005656bb:
  fVar2 = (float10)FUN_0054fad0(_DAT_00950760,uVar1,_DAT_00925018 + _DAT_00925018);
  _DAT_00950760 = (float)fVar2;
  return;
}

