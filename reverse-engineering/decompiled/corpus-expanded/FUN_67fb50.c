/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67fb50; label: FUN_0067fb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067fb50(int param_1,int *param_2,undefined4 *param_3)

{
  if (-1 < param_1) {
    *param_2 = *(int *)(DAT_0292fc68 + 0x68) + param_1 * 0x6c;
    *param_3 = *(undefined4 *)(*(int *)(DAT_0292fc68 + 0x68) + 0x40 + param_1 * 0x6c);
  }
  return;
}

