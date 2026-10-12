/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a8590; label: FUN_005a8590
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

