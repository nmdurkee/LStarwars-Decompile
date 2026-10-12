/* Ghidra pseudocode, not original source.
 * ev_7e454dac1a79555432f813726d68bcfcf5762a505a2d8dbf5e6e5fb42bc98c3e
 * Entry: 0x54c900; label: FUN_0054c900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0054c900(int param_1)

{
  if (*(int *)(param_1 + 0x68) != 0) {
    FUN_00509ab0();
    return;
  }
  if (((DAT_0093d7f0 != 0) && ((*(uint *)(*(int *)(DAT_0093d7f0 + 0xca4) + 4) & DAT_008022c4) != 0))
     || ((DAT_0093d7f4 != 0 && ((*(uint *)(*(int *)(DAT_0093d7f4 + 0xca4) + 4) & DAT_008022c4) != 0)
         ))) {
    if (*(int *)(param_1 + 0x6c) != 0) {
      *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + -5;
      if (*(short *)(param_1 + 10) < *(short *)(param_1 + 0xe)) {
        *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0x12);
      }
      *(int *)(param_1 + 0x34) = (int)*(short *)(param_1 + 10) - (int)*(short *)(param_1 + 0xe);
      return;
    }
    if (*(int *)(param_1 + 0x70) != 0) {
      *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + 5;
      if (*(short *)(param_1 + 0x12) < *(short *)(param_1 + 10)) {
        *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_1 + 0xe);
      }
      *(int *)(param_1 + 0x34) = (int)*(short *)(param_1 + 10) - (int)*(short *)(param_1 + 0xe);
    }
  }
  return;
}

