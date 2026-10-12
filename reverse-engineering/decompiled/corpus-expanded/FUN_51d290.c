/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51d290; label: FUN_0051d290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0051d290(int param_1,int param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(char *)(param_2 + 0x7a) != '\0') {
    do {
      iVar3 = (int)*(short *)(*(int *)(param_2 + 0x8c) + 2 + iVar5 * 4);
      iVar4 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);
      pcVar1 = (char *)(iVar4 + iVar3 * 8);
      cVar2 = *(char *)(iVar4 + iVar3 * 8);
      while (cVar2 != '\0') {
        if ((**(int **)(pcVar1 + 4) == param_3) ||
           (iVar4 = FUN_0051d290(param_1,param_2,param_3), iVar4 != 0)) {
          return 1;
        }
        iVar5 = iVar5 + 1;
        cVar2 = *pcVar1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*(byte *)(param_2 + 0x7a));
  }
  return 0;
}

