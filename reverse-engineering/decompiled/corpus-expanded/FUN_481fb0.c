/* Ghidra pseudocode, not original source.
 * ev_d287e844ea66f87c3c60c812c2454ec5cd238ea97f1ed9ffb4b19045dfabbd11
 * Entry: 0x481fb0; label: FUN_00481fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00481fb0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xf9);
  }
  return 0;
}

