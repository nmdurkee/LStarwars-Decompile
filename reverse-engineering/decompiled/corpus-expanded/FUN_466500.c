/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466500; label: FUN_00466500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_00466500(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0x107);
  }
  return 0;
}

