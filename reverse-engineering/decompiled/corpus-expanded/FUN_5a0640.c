/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0640; label: FUN_005a0640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0640(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x14) != 0)) && ((*(byte *)(param_1 + 10) & 4) == 0)) {
    FUN_004f1310(*(int *)(param_1 + 0x14),param_1);
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 4;
  }
  return;
}

