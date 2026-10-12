/* Ghidra pseudocode, not original source.
 * ev_d0baaaa1d022e9a6bc644bf87cbac2e9d23f713faf88b9587519a457b813b0f8
 * Entry: 0x6a3e30; label: FUN_006a3e30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006a3e30(uint param_1)

{
  return (float10)(float)(param_1 & 0xbf800000 | 0x3f800000);
}

