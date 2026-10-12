/* Ghidra pseudocode, not original source.
 * ev_b0f5904faee5764ce17927395194cf9c706559b4251213f14920f3fe78cd8be0
 * Entry: 0x43bf40; label: FUN_0043bf40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0043bf40(int param_1)

{
  if ((param_1 != -1) && (param_1 < *DAT_029130e4)) {
    return *(undefined4 *)(DAT_029130e4[8] + 0xc + param_1 * 0x4c);
  }
  return 0;
}

