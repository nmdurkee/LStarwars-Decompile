/* Ghidra pseudocode, not original source.
 * ev_c97b225204041db9abadf07c9fc18e64db4e00ddeb87fb2f1b5eee4128d34da7
 * Entry: 0x74d630; label: FUN_0074d630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0074d630(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    *param_1 = *param_3;
    param_1 = param_1 + 1;
  }
  return;
}

