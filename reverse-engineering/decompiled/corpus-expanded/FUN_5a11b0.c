/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a11b0; label: FUN_005a11b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a11b0(int param_1,int param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    for (puVar2 = *(undefined4 **)(param_1 + 0x18); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if (puVar2[4] != 0) {
        puVar1 = (uint *)(puVar2[4] + 0x50);
        *puVar1 = *puVar1 ^ (param_2 * 8 ^ *(uint *)(puVar2[4] + 0x50)) & 8;
      }
    }
  }
  return 1;
}

