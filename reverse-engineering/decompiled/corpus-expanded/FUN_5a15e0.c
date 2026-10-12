/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a15e0; label: FUN_005a15e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a15e0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      FUN_005cfc00(puVar1 + 1,param_2);
    }
  }
  return;
}

