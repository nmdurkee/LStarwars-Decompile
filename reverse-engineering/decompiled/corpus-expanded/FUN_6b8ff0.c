/* Ghidra pseudocode, not original source.
 * ev_9f880a640db7021abf6bd9453b6c2d9d41a7c75291a178dd1542c0e98d960678
 * Entry: 0x6b8ff0; label: FUN_006b8ff0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b8ff0(byte param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0xa50) = (uint)param_1;
  return;
}

