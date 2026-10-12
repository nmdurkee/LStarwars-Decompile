/* Ghidra pseudocode, not original source.
 * ev_8b33ce688355ba097f8d2f702831fda396d81ac3370e92e38da24fe76235d9ff
 * Entry: 0x466820; label: FUN_00466820
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00466820(int param_1)

{
  if (*(void **)(param_1 + 0x800) != (void *)0x0) {
    _memset(*(void **)(param_1 + 0x800),0,0x630);
  }
  return;
}

