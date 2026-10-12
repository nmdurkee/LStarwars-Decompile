/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a8590; label: FUN_005a8590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a8590(short *param_1)

{
  short *psVar1;
  int iVar2;
  
  iVar2 = 0;
  DAT_0095df28 = 0;
  if ((param_1 != (short *)0x0) && (psVar1 = param_1, *param_1 != -1)) {
    do {
      psVar1 = psVar1 + 6;
      iVar2 = iVar2 + 1;
    } while (*psVar1 != -1);
    DAT_0095df28 = iVar2;
    if (iVar2 != 0) {
      DAT_0095df24 = param_1;
      return;
    }
  }
  DAT_0095df24 = (short *)0x0;
  return;
}

