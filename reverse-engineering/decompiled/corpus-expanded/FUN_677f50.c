/* Ghidra pseudocode, not original source.
 * ev_ea7efa1563e3e8089df6b32d8c4fce6d2180bcae0d447e350c78ef2ad3ca8169
 * Entry: 0x677f50; label: FUN_00677f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00677f50(int param_1,int param_2)

{
  *(undefined4 *)(param_1 + -4) = *(undefined4 *)(param_2 + 0x148);
  *(int *)(param_2 + 0x148) = param_1;
  return;
}

