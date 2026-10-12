/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570100; label: FUN_00570100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_00570100(int param_1)

{
  if (param_1 != 0) {
    return *(byte *)(param_1 + 0x17) >> 7;
  }
  return 0;
}

