/* Ghidra pseudocode, not original source.
 * ev_1b30ab9bd7d518785b9e88881958deca55ff5b776c2bbdcc158b73c997cdcb1d
 * Entry: 0x5a0720; label: FUN_005a0720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a0720(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x14) != 0)) {
    if ((*(byte *)(param_1 + 10) & 4) != 0) {
      FUN_004f1410(*(int *)(param_1 + 0x14),param_1);
      *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) & 0xfffb;
    }
    FUN_005a0670(param_1);
  }
  return;
}

