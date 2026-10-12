/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0570; label: FUN_005a0570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0570(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((-1 < param_1) && (param_1 < DAT_00956614)) {
    iVar1 = *(int *)(DAT_0095661c + param_1 * 4);
    iVar2 = 0;
    if (0 < DAT_00956618) {
      do {
        *(undefined1 *)(iVar2 + iVar1) = 0;
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_00956618);
    }
  }
  return;
}

