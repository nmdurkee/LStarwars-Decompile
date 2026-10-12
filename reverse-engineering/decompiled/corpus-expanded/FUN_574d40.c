/* Ghidra pseudocode, not original source.
 * ev_4db18bd42a1a952b6bcb755249e03b5029cd140d39c0a6d9a87cb77874782c83
 * Entry: 0x574d40; label: FUN_00574d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00574d40(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  if ((param_1 != 0) && (iVar2 = 0, 0 < DAT_00951360)) {
    puVar1 = (undefined1 *)(param_1 + 3);
    do {
      puVar1[-1] = 1;
      *puVar1 = 1;
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0xc;
    } while (iVar2 < DAT_00951360);
  }
  return;
}

