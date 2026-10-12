/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51ad80; label: FUN_0051ad80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0051ad80(int param_1,int param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_2 != 0) ||
      ((((param_1 != 0 && (pcVar1 = *(char **)(param_1 + 0x10), pcVar1 != (char *)0x0)) &&
        (*pcVar1 != '\0')) && (param_2 = *(int *)(pcVar1 + 8), param_2 != 0)))) &&
     (iVar4 = 0, *(char *)(param_2 + 0x10) != '\0')) {
    iVar3 = 0;
    do {
      iVar2 = *(int *)(iVar3 + *(int *)(param_2 + 0x7c));
      if (iVar2 != 0) {
        iVar2 = FUN_004f8b10(iVar2,param_3);
        if (iVar2 == 0) {
          return iVar4 * 0x5c + *(int *)(param_2 + 0x7c);
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x5c;
    } while (iVar4 < (int)(uint)*(byte *)(param_2 + 0x10));
  }
  return 0;
}

