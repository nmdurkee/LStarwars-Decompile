/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d9370; label: FUN_006d9370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_006d9370(int param_1)

{
  if (param_1 - 10U < 4) {
    return 0;
  }
  return *(undefined1 *)(param_1 * 0x17c + 0x4e50 + DAT_02975144);
}

