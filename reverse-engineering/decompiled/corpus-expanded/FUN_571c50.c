/* Ghidra pseudocode, not original source.
 * ev_565248e81838fc57af25e3b2c05c11c2e8daf24aacbb3d036db872a2a4b2fd33
 * Entry: 0x571c50; label: FUN_00571c50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00571c50(int param_1)

{
  *(undefined4 *)(param_1 + 0x100) = 0x40a00000;
  if ((*(byte *)(param_1 + 0x20a) & 1) != 0) {
    *(undefined4 *)(param_1 + 0x100) = 0x40200000;
  }
  return;
}

