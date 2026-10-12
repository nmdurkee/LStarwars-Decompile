/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x603530; label: FUN_00603530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00603530(int param_1,int param_2)

{
  uint *puVar1;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar1 = DAT_009736e0;
  *(uint *)(*(int *)(param_1 + 0x14) + 4) = *DAT_009736e0;
  *(uint *)(param_1 + 0x24) = *puVar1;
  *puVar1 = *puVar1 + param_2 * 0x10;
  *(undefined1 *)*puVar1 = 0x8d;
  *(undefined1 *)(*puVar1 + 1) = 1;
  *(int *)(*puVar1 + 4) = *(int *)(param_1 + 0x18) + 0x10;
  *(uint *)(param_1 + 0x14) = *puVar1;
  *puVar1 = *puVar1 + 0x10;
  return;
}

