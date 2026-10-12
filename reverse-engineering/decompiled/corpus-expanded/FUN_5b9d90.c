/* Ghidra pseudocode, not original source.
 * ev_3bb2d5213416039971b6dd1caa939c59b1318a27f895c0ebb43a5b863f1b474b
 * Entry: 0x5b9d90; label: FUN_005b9d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b9d90(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1 * 0x19660d + 0x3c6ef35f;
  *param_1 = uVar1;
  return (float10)((float)(uVar1 & 0x7fffff | 0x3f800000) - 1.0);
}

