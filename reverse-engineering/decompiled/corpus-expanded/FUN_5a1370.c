/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1370; label: FUN_005a1370
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005a1370(int param_1)

{
  undefined4 *puVar1;
  
  if (param_1 != 0) {
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[4] != 0) {
        return (float10)*(float *)(puVar1[4] + 0x4c);
      }
    }
  }
  return (float10)0;
}

