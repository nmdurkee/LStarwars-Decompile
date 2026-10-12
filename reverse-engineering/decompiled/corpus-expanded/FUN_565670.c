/* Ghidra pseudocode, not original source.
 * ev_e3b3033091aeb82eb30298db917b9f24103ba523fce1c25e6a380c5931a7a891
 * Entry: 0x565670; label: FUN_00565670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

