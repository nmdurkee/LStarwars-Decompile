/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b8f90; label: FUN_006b8f90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8f90(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 4))(*(undefined4 *)(in_ECX + 0xc),DAT_02973acc,param_1,0);
  return;
}

