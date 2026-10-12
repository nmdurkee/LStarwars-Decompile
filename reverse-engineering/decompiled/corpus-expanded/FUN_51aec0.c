/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51aec0; label: FUN_0051aec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0051aec0(int param_1,int param_2,byte param_3,byte param_4)

{
  char *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  
  if (((param_2 != 0) ||
      ((((param_1 != 0 && (pcVar1 = *(char **)(param_1 + 0x10), pcVar1 != (char *)0x0)) &&
        (*pcVar1 != '\0')) && (param_2 = *(int *)(pcVar1 + 8), param_2 != 0)))) &&
     (param_3 < *(byte *)(param_2 + 0x10))) {
    iVar3 = (uint)param_3 * 0x5c + *(int *)(param_2 + 0x7c);
    if (param_3 != param_4) {
      uVar6 = (uint)*(byte *)(iVar3 + 0x28);
      iVar4 = 0;
      if (uVar6 != 0) {
        piVar2 = *(int **)(iVar3 + 0x34);
        piVar5 = piVar2;
        do {
          if ((*(byte *)(*piVar5 + 0x10) == param_4) || (*(byte *)(*piVar5 + 0x11) == param_4)) {
            return piVar2[iVar4];
          }
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar4 < (int)uVar6);
      }
    }
  }
  return 0;
}

