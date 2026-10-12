/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x570a60; label: FUN_00570a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00570a60(int param_1)

{
  if (param_1 != 0) {
    *(undefined1 *)(param_1 + 10) = 1;
    *(undefined4 *)(param_1 + 4) = 0x3f800000;
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  return;
}

