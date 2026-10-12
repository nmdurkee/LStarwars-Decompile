/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60c7f0; label: FUN_0060c7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_0060c7f0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = *(uint *)(in_ECX + 4);
  uVar1 = *(uint *)(in_ECX + 8);
  *param_1 = 0;
  if (uVar1 < uVar2) {
    FUN_006e9fe6();
  }
  *param_1 = in_ECX;
  param_1[1] = uVar2;
  return param_1;
}

