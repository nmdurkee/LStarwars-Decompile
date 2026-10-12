/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x7422a0; label: FUN_007422a0
 */

void FUN_007422a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_stack_00000020;
  
  FUN_00743910(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x14) = in_stack_00000020;
  return;
}

