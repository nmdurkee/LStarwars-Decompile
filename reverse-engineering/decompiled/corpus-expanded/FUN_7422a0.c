/* Ghidra pseudocode, not original source.
 * ev_62401c78f713d82b54f61245081db5d782857868d5d6aacf9838dab8303215ce
 * Entry: 0x7422a0; label: FUN_007422a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007422a0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_stack_00000020;
  
  FUN_00743910(param_1,param_2,param_3);
  *(undefined4 *)(param_1 + 0x14) = in_stack_00000020;
  return;
}

