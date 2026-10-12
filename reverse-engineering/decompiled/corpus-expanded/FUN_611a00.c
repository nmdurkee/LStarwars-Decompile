/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611a00; label: FUN_00611a00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611a00(int param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + param_1;
  }
  return;
}

