/* Ghidra pseudocode, not original source.
 * ev_7628bb02d4360686842aba648e3e8351ab050d06c55da9366e8a0a89d745bc47
 * Entry: 0x6a3de0; label: FUN_006a3de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006a3de0(int *param_1)

{
  return ((int)(param_1[1] + 7 + (param_1[1] + 7 >> 0x1f & 7U)) >> 3) + *param_1;
}

