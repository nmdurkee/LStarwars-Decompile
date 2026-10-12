/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6dfc40; label: FUN_006dfc40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dfc40(int *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 0x48))(param_1,param_2,param_3);
  }
  return;
}

