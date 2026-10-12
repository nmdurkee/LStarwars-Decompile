/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574d80; label: FUN_00574d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00574d80(int param_1)

{
  short sVar1;
  int iVar2;
  
  if (DAT_00951370 != 0) {
    iVar2 = 0;
    sVar1 = *DAT_00951374;
    while ((sVar1 != -1 && (iVar2 < 0x40))) {
      if (DAT_00951374[iVar2 * 2] == param_1) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      sVar1 = DAT_00951374[iVar2 * 2];
    }
  }
  return 0xff;
}

