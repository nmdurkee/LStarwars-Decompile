/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1610; label: FUN_005a1610
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a1610(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      FUN_00552760(puVar1 + 1,*(undefined4 *)(puVar1[4] + 0x4c));
    }
  }
  return;
}

