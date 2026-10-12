/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9dd0; label: FUN_005b9dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b9dd0(void)

{
  DAT_0095e5d4 = DAT_0095e5d4 * 0x19660d + 0x3c6ef35f;
  return (float10)((float)(DAT_0095e5d4 & 0x7fffff | 0x3f800000) - 1.0);
}

