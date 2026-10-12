/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440120; label: FUN_00440120
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00440120(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  if (DAT_00923904 != (code *)0x0) {
    puVar1 = (undefined4 *)(*DAT_00923904)(param_1,param_2);
    if (puVar1 != (undefined4 *)0x0) {
      return *puVar1;
    }
  }
  return 0;
}

