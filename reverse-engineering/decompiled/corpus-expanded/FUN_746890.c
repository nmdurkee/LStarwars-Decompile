/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746890; label: FUN_00746890
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00746890(int *param_1,int param_2)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  
  do {
    if (*param_1 != 0) {
      FUN_00746890(*param_1,param_2);
    }
    pcVar2 = (char *)param_1[2];
    pcVar3 = pcVar2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar6 = (char *)(param_2 + -1);
    do {
      pcVar5 = pcVar6 + 1;
      pcVar6 = pcVar6 + 1;
    } while (*pcVar5 != '\0');
    pcVar5 = pcVar2;
    for (uVar4 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar6 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar6 = pcVar6 + 4;
    }
    for (uVar4 = (int)pcVar3 - (int)pcVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar6 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar6 = pcVar6 + 1;
    }
    param_1 = (int *)param_1[1];
  } while (param_1 != (int *)0x0);
  return;
}

