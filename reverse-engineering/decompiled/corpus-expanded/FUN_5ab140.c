/* Ghidra pseudocode, not original source.
 * ev_51f4537ed7c57c9a0fa7f304a7a0f3427cc608dfecd65a4b8280241ed2e1f797
 * Entry: 0x5ab140; label: FUN_005ab140
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int * FUN_005ab140(short *param_1,int param_2,char param_3,int param_4,char param_5)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)0x0;
  if ((((param_1 != (short *)0x0) && (sVar1 = param_1[1], sVar1 < *param_1)) && (param_2 != 0)) &&
     (param_4 != 0)) {
    iVar3 = 0;
    piVar2 = *(int **)(param_1 + 2);
    if (0 < sVar1) {
      do {
        if (((*piVar2 == param_2) && (param_5 == *(char *)((int)piVar2 + 9))) &&
           (param_4 == piVar2[1])) {
          if ((char)piVar2[2] != param_3) {
            *(undefined1 *)(piVar2 + 2) = 0xff;
          }
          return piVar2;
        }
        iVar3 = iVar3 + 1;
        piVar2 = piVar2 + 4;
      } while (iVar3 < param_1[1]);
    }
    piVar2 = *(int **)(param_1 + 2) + sVar1 * 4;
    param_1[1] = sVar1 + 1;
    *piVar2 = param_2;
    *(char *)(piVar2 + 2) = param_3;
    piVar2[1] = param_4;
    *(char *)((int)piVar2 + 9) = param_5;
  }
  return piVar2;
}

