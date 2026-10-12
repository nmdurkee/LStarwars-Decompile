/* Ghidra pseudocode, not original source.
 * ev_04afb3492a8afd57c97545bb5c0eddf79bdf86b5b15013378a1fe0d824f4c6ce
 * Entry: 0x4f21a0; label: FUN_004f21a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f21a0(int param_1)

{
  if (((ushort)((short)param_1 - 0x61U) < 0x1a) || ((ushort)((short)param_1 - 0xe0U) < 0x20)) {
    param_1 = param_1 + 0xffe0;
  }
  return param_1;
}

