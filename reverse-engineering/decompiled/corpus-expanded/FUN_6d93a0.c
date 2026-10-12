/* Ghidra pseudocode, not original source.
 * ev_901c6aaecd0b47868ef1d3f758584dfae83b8347f4e0d529523c41e91b06b177
 * Entry: 0x6d93a0; label: FUN_006d93a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_006d93a0(int param_1)

{
  if (3 < param_1 - 10U) {
    return 0;
  }
  return *(undefined1 *)(param_1 * 0x17c + 0x4e51 + DAT_02975144);
}

