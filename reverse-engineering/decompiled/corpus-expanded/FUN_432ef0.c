/* Ghidra pseudocode, not original source.
 * ev_a581b26cc49c1240ca9fc8201471236b1c0a2571dfff42173a4e3442f2e0fd27
 * Entry: 0x432ef0; label: FUN_00432ef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432ef0(int param_1,undefined4 param_2)

{
  undefined2 local_4;
  
  *(undefined4 *)(param_1 + 0x130) = 0xffff8000;
  local_4 = (undefined2)(int)ROUND(_DAT_00925018 * -32768.0);
  *(undefined2 *)(param_1 + 0x13c) = local_4;
  FUN_00432a70(param_2);
  return;
}

