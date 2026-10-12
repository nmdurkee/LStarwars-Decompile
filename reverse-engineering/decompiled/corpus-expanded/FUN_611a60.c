/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611a60; label: FUN_00611a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00611a60(int param_1)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x29c) + param_1;
}

