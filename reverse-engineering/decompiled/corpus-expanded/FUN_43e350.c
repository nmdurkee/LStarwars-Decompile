/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43e350; label: FUN_0043e350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0043e350(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return ~(*(uint *)(*param_1 + 0x60) >> 1) & 1;
  }
  return 0;
}

