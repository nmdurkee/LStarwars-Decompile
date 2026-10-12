/* Ghidra pseudocode, not original source.
 * ev_e37398024b26761df01c7e6d1f7f3789c673fd129cb2ff02e0ba3ea718b801df
 * Entry: 0x45e280; label: FUN_0045e280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0045e280(int param_1,int param_2,float param_3)

{
  if (*(int *)(param_1 + 0x14) == 0) {
    *(undefined4 *)(param_1 + 0x14) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0x3f19999a;
  }
  else if (*(int *)(param_1 + 0x14) == 1) {
    param_3 = *(float *)(param_1 + 0x18) + param_3;
    *(float *)(param_1 + 0x18) = param_3;
    if (*(float *)(param_1 + 0x1c) < param_3 != (*(float *)(param_1 + 0x1c) == param_3)) {
      FUN_00486940(*(undefined1 *)(param_2 + 0xba));
      return;
    }
  }
  return;
}

