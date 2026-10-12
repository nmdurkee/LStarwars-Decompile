/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x69ff70; label: FUN_0069ff70
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

char * FUN_0069ff70(int *param_1,char *param_2,int param_3)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined2 *puVar7;
  int iVar8;
  undefined4 uStack_18;
  int local_8;
  
  local_8 = 0;
  pcVar1 = param_2 + 1;
  pcVar5 = param_2;
  do {
    cVar3 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar3 != '\0');
  uStack_18 = 0x69ff9c;
  iVar4 = -(int)(pcVar5 + (2 - (int)pcVar1));
  iVar8 = iVar4 - (int)param_2;
  do {
    cVar3 = *param_2;
    param_2[(int)(&stack0xffffffec + iVar8)] = cVar3;
    param_2 = param_2 + 1;
  } while (cVar3 != '\0');
  puVar7 = (undefined2 *)((int)&uStack_18 + iVar4 + 3);
  do {
    pcVar2 = (char *)((int)puVar7 + 1);
    puVar7 = (undefined2 *)((int)puVar7 + 1);
  } while (*pcVar2 != '\0');
  *puVar7 = 0x3d;
  iVar8 = 0;
  if (0 < param_1[2]) {
    do {
      *(undefined4 *)((int)&uStack_18 + iVar4) = 0x69ffe2;
      iVar6 = FUN_0069ff20();
      if (iVar6 == 0) {
        if (param_3 == local_8) {
          return pcVar5 + *(int *)(*param_1 + iVar8 * 4) + (1 - (int)pcVar1);
        }
        local_8 = local_8 + 1;
      }
      iVar8 = iVar8 + 1;
    } while (iVar8 < param_1[2]);
  }
  return (char *)0x0;
}

