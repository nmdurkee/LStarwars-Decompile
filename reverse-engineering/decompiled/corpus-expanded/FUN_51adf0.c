/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51adf0; label: FUN_0051adf0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0051adf0(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  if ((param_2 != 0) ||
     ((((param_1 != 0 && (pcVar1 = *(char **)(param_1 + 0x10), pcVar1 != (char *)0x0)) &&
       (*pcVar1 != '\0')) && (param_2 = *(int *)(pcVar1 + 8), param_2 != 0)))) {
    iVar3 = FUN_0051ad80(param_1,param_2,param_3);
    iVar4 = FUN_0051ad80(param_1,param_2,param_4);
    if (((iVar3 != 0) && (iVar4 != 0)) && (iVar3 != iVar4)) {
      uVar2 = (iVar4 - *(int *)(param_2 + 0x7c)) / 0x5c;
      iVar4 = 0;
      if (*(byte *)(iVar3 + 0x28) != 0) {
        piVar5 = *(int **)(iVar3 + 0x34);
        do {
          if (*(byte *)(*piVar5 + 0x10) == uVar2) {
            *param_5 = 1;
            return *(undefined4 *)(*(int *)(iVar3 + 0x34) + iVar4 * 4);
          }
          if (*(byte *)(*piVar5 + 0x11) == uVar2) {
            *param_5 = 0;
            return *(undefined4 *)(*(int *)(iVar3 + 0x34) + iVar4 * 4);
          }
          iVar4 = iVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar4 < (int)(uint)*(byte *)(iVar3 + 0x28));
      }
    }
  }
  return 0;
}

