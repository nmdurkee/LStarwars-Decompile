/* Ghidra pseudocode, not original source.
 * ev_5297a07726b91b44a37fb2d5f8434cfe859173f36b4cfd633cbfa32546391649
 * Entry: 0x5954f0; label: FUN_005954f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

