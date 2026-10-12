/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f2d80; label: FUN_004f2d80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_004f2d80(byte param_1)

{
  if (((byte)(param_1 + 0x9f) < 0x1a) || (0xdf < param_1)) {
    param_1 = param_1 - 0x20;
  }
  return param_1;
}

