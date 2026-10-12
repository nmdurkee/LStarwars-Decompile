/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x6034b0; label: FUN_006034b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_006034b0(int param_1,undefined1 param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  *DAT_009736e0 = *DAT_009736e0 + 0xf & 0xfffffff0;
  puVar2 = DAT_009736e0;
  *(uint *)(*(int *)(param_1 + 0x14) + 4) = *DAT_009736e0;
  *(undefined1 *)*puVar2 = param_2;
  *(undefined1 *)(*puVar2 + 1) = 3;
  uVar1 = *puVar2;
  if (param_3 == 0) {
    *(uint *)(uVar1 + 4) = uVar1 + 0x20;
  }
  else {
    *(int *)(uVar1 + 4) = param_3;
  }
  *(undefined1 *)(*puVar2 + 0x10) = 0x8d;
  *(undefined1 *)(*puVar2 + 0x11) = 1;
  *(int *)(*puVar2 + 0x14) = *(int *)(param_1 + 0x18) + 0x10;
  *(uint *)(param_1 + 0x14) = *puVar2 + 0x10;
  *puVar2 = *puVar2 + 0x20;
  return ~-(uint)(param_3 != 0) & (uint)puVar2;
}

