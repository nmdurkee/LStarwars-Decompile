/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab1e0; label: FUN_005ab1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005ab1e0(int param_1,int param_2,int param_3,char param_4,undefined4 param_5,code *param_6
                  )

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_3 == 0) && (param_2 != 0)) {
    param_3 = *(int *)(param_2 + 0x424);
    param_4 = *(char *)(param_2 + 0x428);
  }
  if ((param_1 != 0) && (param_3 != 0)) {
    piVar2 = *(int **)(param_1 + 4);
    iVar3 = 0;
    if (0 < *(short *)(param_1 + 2)) {
      do {
        if (((*piVar2 == param_3) &&
            ((((char)piVar2[2] == -1 || ((char)piVar2[2] == param_4)) &&
             ((char)param_5 == *(char *)((int)piVar2 + 9))))) &&
           ((param_6 == (code *)0x0 ||
            (iVar1 = (*param_6)(piVar2,param_2,param_3,param_4,param_5), iVar1 == 0)))) {
          return piVar2;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 4;
      } while (iVar3 < *(short *)(param_1 + 2));
    }
  }
  return (int *)0x0;
}

