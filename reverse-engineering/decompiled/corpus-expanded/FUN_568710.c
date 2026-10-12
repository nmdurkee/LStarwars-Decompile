/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x568710; label: FUN_00568710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00568710(int param_1)

{
  if (param_1 != 0) {
    if (*(short *)(param_1 + 0x102) != -1) {
      FUN_0067c930((int)*(short *)(param_1 + 0x102));
      *(undefined2 *)(param_1 + 0x102) = 0xffff;
    }
    if (*(short *)(param_1 + 0x104) != -1) {
      FUN_0067c930((int)*(short *)(param_1 + 0x104));
      *(undefined2 *)(param_1 + 0x104) = 0xffff;
    }
  }
  return;
}

