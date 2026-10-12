/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0550; label: FUN_005a0550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a0550(int param_1)

{
  if ((-1 < param_1) && (param_1 < DAT_00956614)) {
    return *(undefined4 *)(DAT_0095661c + param_1 * 4);
  }
  return 0;
}

