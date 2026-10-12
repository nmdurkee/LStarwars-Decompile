/* Ghidra pseudocode, not original source.
 * ev_6f25f465777d6c282cbfa6a77d593954d589f2e76f9dc6caa100c42a001a6af1
 * Entry: 0x6f87d0; label: ___AdjustPointer
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* Library Function - Single Match
    ___AdjustPointer
   
   Library: Visual Studio 2005 Release */

int ___AdjustPointer(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2 + param_1;
  if (-1 < param_2[1]) {
    iVar1 = iVar1 + *(int *)(*(int *)(param_2[1] + param_1) + param_2[2]) + param_2[1];
  }
  return iVar1;
}

