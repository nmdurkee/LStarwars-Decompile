/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d37a0; label: FUN_006d37a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006d37a0(int param_1,uint param_2)

{
  if (param_1 < 0) {
    return param_1 * 2 + 1U ^ param_2 ^ 0x12345678;
  }
  return param_1 * 2 ^ param_2 ^ 0x12345678;
}

