/* Ghidra pseudocode, not original source.
 * ev_4cbe307265f31e413c5f7cc9b7da0764bbafe6907e0e37f5fb37c4e62049af07
 * Entry: 0x69ad10; label: FUN_0069ad10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0069ad10(int param_1)

{
  FUN_004ffaa0(DAT_02973a00);
  if (*(int *)(param_1 + 0x318) != 0) {
    *(int *)(*(int *)(param_1 + 0x318) + 0x110) = *(int *)(*(int *)(param_1 + 0x318) + 0x110) + -1;
  }
  *(undefined4 *)(param_1 + 0x318) = 0;
  FUN_004ffac0(DAT_02973a00);
  return 1;
}

