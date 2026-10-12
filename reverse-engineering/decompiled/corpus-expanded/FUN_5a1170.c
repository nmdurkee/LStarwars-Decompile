/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1170; label: FUN_005a1170
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a1170(int param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 != 0) && ((*(int *)(param_1 + 0xc) == 1 || (*(int *)(param_1 + 0xc) == 3)))) {
    *(ushort *)(param_1 + 10) = *(ushort *)(param_1 + 10) | 2;
    for (puVar1 = *(undefined4 **)(param_1 + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (puVar1[4] != 0) {
        *(uint *)(puVar1[4] + 0x50) = *(uint *)(puVar1[4] + 0x50) & 0xfffffffe;
      }
    }
  }
  return 1;
}

