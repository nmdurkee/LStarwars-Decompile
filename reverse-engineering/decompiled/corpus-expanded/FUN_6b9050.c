/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b9050; label: FUN_006b9050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b9050(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = *param_1;
  *(undefined4 *)(in_ECX + 0x14) = param_1[1];
  *(undefined4 *)(in_ECX + 0x18) = param_1[2];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[3];
  FUN_00620f10((undefined4 *)(in_ECX + 0x10));
  return;
}

