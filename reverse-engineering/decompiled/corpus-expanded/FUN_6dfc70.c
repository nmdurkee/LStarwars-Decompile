/* Ghidra pseudocode, not original source.
 * ev_9a76e25c08ce4dcda3c08de929e5a103c2765ccb900e87aba0770623e17ea5fe
 * Entry: 0x6dfc70; label: FUN_006dfc70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006dfc70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5,undefined4 param_6)

{
  if (param_5 == 0) {
    FUN_006e47d0(param_2,param_3,param_4,0,param_1,1,param_6);
    return;
  }
  FUN_006e47d0(param_2,param_3,1,1,param_1,0,param_6);
  return;
}

