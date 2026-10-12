/* Ghidra pseudocode, not original source.
 * ev_35392dc412ffe2b2a558f5a6ba3fa7479ff279a31c4c87c94d67c76968103d24
 * Entry: 0x615ce0; label: FUN_00615ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00615ce0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar3 = param_2;
  iVar4 = FUN_006be780(param_2);
  iVar2 = param_1;
  piVar1 = (int *)(in_ECX + 0xd1b4 + iVar4 * 0xc);
  *(undefined4 *)(param_1 + 4) = 0;
  *(int *)(param_1 + 8) = piVar1[1];
  if (piVar1[1] != 0) {
    *(int *)(piVar1[1] + 4) = param_1;
  }
  piVar1[1] = param_1;
  if (*piVar1 == 0) {
    *piVar1 = param_1;
  }
  piVar1[2] = piVar1[2] + 1;
  FUN_006154f0(param_1,iVar3,&param_2,&param_1);
  piVar1 = (int *)(in_ECX + 0xd4b4 + iVar4 * 4);
  *piVar1 = *piVar1 + param_2;
  *(short *)(iVar2 + 0x14) = (short)param_2;
  *(undefined2 *)(iVar2 + 0x16) = (undefined2)param_1;
  return;
}

