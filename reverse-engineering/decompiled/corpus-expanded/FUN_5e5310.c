/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e5310; label: FUN_005e5310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005e5310(int param_1)

{
  if (param_1 < 1) {
    return 0;
  }
  return *(undefined4 *)(DAT_0097157c + -4 + param_1 * 4);
}

