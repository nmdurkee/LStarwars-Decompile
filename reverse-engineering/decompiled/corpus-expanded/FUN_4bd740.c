/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bd740; label: FUN_004bd740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004bd740(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xfa);
  }
  return 0;
}

