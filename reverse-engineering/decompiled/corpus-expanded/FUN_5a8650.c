/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8650; label: FUN_005a8650
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

short * FUN_005a8650(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if ((DAT_0095df24 != (short *)0x0) && (psVar2 = DAT_0095df24, 0 < DAT_0095df28)) {
    do {
      if (*psVar2 == param_1) {
        return DAT_0095df24 + iVar1 * 6;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 6;
    } while (iVar1 < DAT_0095df28);
  }
  return (short *)0x0;
}

