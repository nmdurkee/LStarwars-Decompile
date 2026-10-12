/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45e400; label: FUN_0045e400
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045e400(int param_1)

{
  if (*(int *)(*(int *)(param_1 + 0x124) + 0x14) == -1) {
    *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x18) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x124) + 0x14) = 0;
  }
  return;
}

