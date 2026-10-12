/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7e10; label: FUN_004e7e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e7e10(void)

{
  int iVar1;
  
  if (DAT_0087a7f0 == 0) {
    DAT_0087a7f0 = FUN_0055ce20((int)DAT_007f199c,1,1,1,0);
  }
  if (DAT_00951b50 == 0) {
    if ((DAT_0087aa5c == 0) || (iVar1 = DAT_0087a7f0, *(float *)(DAT_0087aa5c + 0x28) != 1.0)) {
      iVar1 = 0;
    }
    FUN_004ba2d0(iVar1);
    if ((((DAT_0087aa60 != 0) && (*(float *)(DAT_0087aa60 + 0x28) == 1.0)) && (DAT_0087a7f0 != 0))
       && ((*(char *)(DAT_0087a7f0 + 0x28b) != '\0' || (*(char *)(DAT_0087a7f0 + 0x107f) == '\0'))))
    {
      if (DAT_0093b2a4 != 0) {
        FUN_0057a5b0();
        return;
      }
      if (DAT_0087b230 != 0) {
        FUN_0057a580();
        return;
      }
    }
  }
  return;
}

