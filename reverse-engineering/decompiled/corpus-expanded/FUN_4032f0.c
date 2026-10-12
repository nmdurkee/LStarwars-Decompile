/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x4032f0; label: FUN_004032f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004032f0(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  return *param_1 + 0x10;
}

