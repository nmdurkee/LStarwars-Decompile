/* Ghidra pseudocode, not original source.
 * ev_a67b1d7875d7de5d33c5f2e23ff7bb43dcd4ff34aaa1a90d4ca40378ea72f78c
 * Entry: 0x6039d0; label: FUN_006039d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006039d0(int param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  
  *(undefined4 *)(param_2 + 0x7c) = 0;
  if (*(int *)(param_1 + 0x7c) != 0) {
    puVar1 = (undefined4 *)(*param_3 + 3U & 0xfffffffc);
    *param_3 = (*param_3 + 3U & 0xfffffffc) + 4;
    *puVar1 = **(undefined4 **)(param_1 + 0x7c);
    *(undefined4 **)(param_2 + 0x7c) = puVar1;
  }
  return;
}

