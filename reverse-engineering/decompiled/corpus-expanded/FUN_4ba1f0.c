/* Ghidra pseudocode, not original source.
 * ev_994c8ab95260a4a020e9117574c628d5ef7b33cde61134a1d0677698b3534ab7
 * Entry: 0x4ba1f0; label: FUN_004ba1f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ba1f0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = _DAT_0087b928;
  if (((unaff_ESI != 0) && (*(char *)(unaff_ESI + 0x28b) == '\0')) &&
     ((*(byte *)(unaff_ESI + 0x1fc) & 0x80) == 0)) {
    if (_DAT_00950780 == 0.0) {
      FUN_0055b830((int)*(short *)(unaff_ESI + 0x1064),0,_DAT_007fc3a0,0,_DAT_007fc3a4,0xa7,
                   _DAT_0087b928,_DAT_0087b928,1,0);
      FUN_004b88b0(0,_DAT_007fc398,_DAT_007fc39c,0x3f800000,0,uVar1,1);
      return 1;
    }
    DAT_0087b9b4 = 0;
  }
  return 0;
}

