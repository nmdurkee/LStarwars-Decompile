/* Ghidra pseudocode, not original source.
 * ev_26d1fac8fd457d7aa06190d117e50b4f3cb6f2e0dd1b5e3302fd798cb5ca6742
 * Entry: 0x43cf70; label: FUN_0043cf70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0043cf70(int param_1,void *param_2)

{
  if ((param_1 != 0) && (param_2 != (void *)0x0)) {
    FUN_004f1410(param_1 + 0x10,param_2);
    _memset(param_2,0,0xa8);
    FUN_004f1310(param_1 + 8,param_2);
  }
  return;
}

