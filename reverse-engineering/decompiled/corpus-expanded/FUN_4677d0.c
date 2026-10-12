/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x4677d0; label: FUN_004677d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004677d0(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (((*(uint *)(param_1 + 0xa0) & 0x100) != 0) && (*(short *)(param_2 + 0x106c) != -1)) {
    for (puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x28) + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if (*(short *)(puVar1[9] + 2) == *(short *)(param_2 + 0x106c)) {
        return 1;
      }
    }
  }
  return 0;
}

