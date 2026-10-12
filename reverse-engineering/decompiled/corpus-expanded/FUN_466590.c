/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466590; label: FUN_00466590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_00466590(int *param_1)

{
  return *(byte *)(*param_1 + 0x2a) & 1;
}

