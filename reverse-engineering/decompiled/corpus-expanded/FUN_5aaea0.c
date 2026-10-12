/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5aaea0; label: FUN_005aaea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005aaea0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return (int)*(char *)(*param_1 + 0x34);
  }
  return 0;
}

