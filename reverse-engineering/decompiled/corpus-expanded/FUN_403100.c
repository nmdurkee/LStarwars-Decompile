/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403100; label: FUN_00403100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00403100(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf6);
  }
  return 0;
}

