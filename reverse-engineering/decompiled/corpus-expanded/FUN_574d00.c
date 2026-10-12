/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574d00; label: FUN_00574d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00574d00(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < DAT_00951360) {
    psVar2 = (short *)(DAT_00951354 + 0x8a);
    do {
      if (*psVar2 == param_1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x4e;
    } while (iVar1 < DAT_00951360);
  }
  return -1;
}

