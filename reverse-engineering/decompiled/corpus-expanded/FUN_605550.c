/* Ghidra pseudocode, not original source.
 * ev_c781f6f2f7d78097ae9ff869f9175a8231755f2e9224784a2b208dfae7521271
 * Entry: 0x605550; label: FUN_00605550
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00605550(int param_1,int param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_2 = param_2 + -8) {
    param_3[-2] = *(undefined4 *)(param_2 + -8);
    param_3[-1] = *(undefined4 *)(param_2 + -4);
    param_3 = param_3 + -2;
  }
  return;
}

