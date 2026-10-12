/* Ghidra pseudocode, not original source.
 * ev_2e86f2171d5c14e65a9d827277689f6eb238c30686d251b2df2a036861678988
 * Entry: 0x4a9900; label: FUN_004a9900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004a9900(int param_1)

{
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x10) != 0) {
    *(undefined2 *)(param_1 + 0x42) = *(undefined2 *)(param_1 + 0x7aa);
    return;
  }
  *(undefined2 *)(param_1 + 0x42) = 1;
  return;
}

