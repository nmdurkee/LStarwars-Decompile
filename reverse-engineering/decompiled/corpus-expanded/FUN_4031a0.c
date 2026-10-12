/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x4031a0; label: FUN_004031a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_004031a0(int *param_1)

{
  return *(byte *)(*param_1 + 0x62) >> 2 & 1;
}

