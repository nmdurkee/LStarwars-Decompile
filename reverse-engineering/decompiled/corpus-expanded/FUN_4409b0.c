/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x4409b0; label: FUN_004409b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004409b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)
           FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),DAT_00802644,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}

