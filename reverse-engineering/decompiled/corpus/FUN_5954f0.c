/* Ghidra analysis pseudocode, not original source.
 * ev_95f339e64e03912db0b4337524e50c5f1fa1cc6c36f27950d42195022949d97c
 * Entry: 0x5954f0; label: FUN_005954f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005954f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *in_stack_0000001c;
  
  FUN_00595110(param_2,param_3);
  _DAT_009716e8 = *in_stack_0000001c;
  _DAT_009716ec = in_stack_0000001c[1];
  _DAT_009716f0 = in_stack_0000001c[2];
  FUN_005fca90(in_stack_0000001c);
  return;
}

