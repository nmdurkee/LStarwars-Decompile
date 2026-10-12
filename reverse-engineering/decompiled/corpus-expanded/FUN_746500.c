/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746500; label: FUN_00746500
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746500(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  *(undefined1 *)(in_ECX + 2) = param_3;
  return;
}

