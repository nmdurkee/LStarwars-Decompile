/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x69fe70; label: FUN_0069fe70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

void FUN_0069fe70(undefined4 param_1,char *param_2,char *param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  undefined2 *puVar8;
  undefined4 auStack_1c [2];
  undefined4 uStack_14;
  
  pcVar4 = param_2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar5 = param_3;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uStack_14 = 0x69fea7;
  iVar2 = -(int)(pcVar4 + (int)(pcVar5 + ((2 - (int)(param_3 + 1)) - (int)(param_2 + 1))));
  iVar3 = iVar2 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(&stack0xfffffff0 + iVar3)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  puVar8 = (undefined2 *)((int)&uStack_14 + iVar2 + 3);
  do {
    pcVar4 = (char *)((int)puVar8 + 1);
    puVar8 = (undefined2 *)((int)puVar8 + 1);
  } while (*pcVar4 != '\0');
  *puVar8 = 0x3d;
  pcVar4 = param_3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  pcVar5 = (char *)((int)&uStack_14 + iVar2 + 3);
  do {
    pcVar7 = pcVar5 + 1;
    pcVar5 = pcVar5 + 1;
  } while (*pcVar7 != '\0');
  pcVar7 = param_3;
  for (uVar6 = (uint)((int)pcVar4 - (int)param_3) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar6 = (int)pcVar4 - (int)param_3 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
    *pcVar5 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar5 = pcVar5 + 1;
  }
  *(undefined1 **)((int)&uStack_14 + iVar2) = &stack0xfffffff0 + iVar2;
  *(undefined4 *)((int)auStack_1c + iVar2 + 4) = param_1;
  *(undefined4 *)((int)auStack_1c + iVar2) = 0x69ff14;
  FUN_0069fdd0();
  return;
}

