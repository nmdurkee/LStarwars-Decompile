/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67c860; label: FUN_0067c860
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0067c860(int param_1)

{
  if (((DAT_0292fc68 != 0) && (-1 < param_1)) && (param_1 < *(int *)(DAT_0292fc68 + 0xa48c))) {
    return *(uint *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4c + param_1 * 0x6c) >> 1 & 1;
  }
  return 0;
}

