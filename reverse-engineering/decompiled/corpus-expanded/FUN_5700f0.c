/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x5700f0; label: FUN_005700f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005700f0(int param_1)

{
  if (param_1 != 0) {
    *(byte *)(param_1 + 0x17) = *(byte *)(param_1 + 0x17) | 0x86;
  }
  return;
}

