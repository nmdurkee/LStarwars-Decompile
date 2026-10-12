/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x4982b0; label: FUN_004982b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004982b0(int param_1)

{
  if ((*(char *)(param_1 + 0x7b5) != 'B') &&
     (((*(char *)(param_1 + 0x7b5) != '\x1c' || (*(int *)(param_1 + 0x790) == 0)) ||
      ((*(uint *)(*(int *)(param_1 + 0x790) + 0xe20) & 0x100) == 0)))) {
    return 0;
  }
  return 1;
}

