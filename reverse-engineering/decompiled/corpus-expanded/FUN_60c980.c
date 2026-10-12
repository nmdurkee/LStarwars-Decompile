/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60c980; label: FUN_0060c980
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0060c980(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != param_2) {
    iVar1 = param_2;
    do {
      iVar2 = iVar1 + -8;
      *(undefined4 *)((param_3 - param_2) + iVar2) = *(undefined4 *)(iVar1 + -8);
      *(undefined4 *)((param_3 - param_2) + 4 + iVar2) = *(undefined4 *)(iVar1 + -4);
      iVar1 = iVar2;
    } while (iVar2 != param_1);
  }
  return param_3 + (param_2 - param_1 >> 3) * -8;
}

