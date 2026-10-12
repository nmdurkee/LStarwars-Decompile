/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55cdf0; label: FUN_0055cdf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055cdf0(int param_1)

{
  if (((*(byte *)(param_1 + 0x1fc) & 0x80) == 0) &&
     ((*(int *)(param_1 + 0xcd0) == 0 ||
      ((*(byte *)(*(int *)(param_1 + 0xcd0) + 0x1fc) & 0x80) == 0)))) {
    return 0;
  }
  return 1;
}

