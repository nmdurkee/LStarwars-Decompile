/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440880; label: FUN_00440880
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00440880(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((*(uint *)(*(int *)(*(int *)(param_3 + 0xd0) + 0x54) + 4) & 0x80000000) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

