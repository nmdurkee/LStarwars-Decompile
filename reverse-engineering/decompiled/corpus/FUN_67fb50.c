/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x67fb50; label: FUN_0067fb50
 */

void FUN_0067fb50(int param_1,int *param_2,undefined4 *param_3)

{
  if (-1 < param_1) {
    *param_2 = *(int *)(DAT_0292fc68 + 0x68) + param_1 * 0x6c;
    *param_3 = *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x40 + param_1 * 0x6c);
  }
  return;
}

