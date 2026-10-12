/* Ghidra pseudocode, not original source.
 * ev_4979805bbb21a8904736e4a261aef1b5206e58d1861917e5f468ac2db6a4df52
 * Entry: 0x611ad0; label: FUN_00611ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611ad0(int param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x20) + 4) != 0) {
    piVar1 = (int *)(*(int *)(in_ECX + 0x20) + 8);
    *piVar1 = *piVar1 + param_1 * param_2;
  }
  return;
}

