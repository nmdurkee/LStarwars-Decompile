/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x7466b0; label: FUN_007466b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_007466b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_004f1ff0(param_1);
  FUN_004ef660();
  *(undefined4 *)(in_ECX + 0x10) = param_2;
  return;
}

