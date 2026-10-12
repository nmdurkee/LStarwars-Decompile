/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a0020; label: FUN_006a0020
 */

/* WARNING: Function: __alloca_probe_16 replaced with injection: alloca_probe */
/* WARNING: Unable to track spacebase fully for stack */

int FUN_006a0020(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined4 uStack_18;
  int local_8;
  
  local_8 = 0;
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uStack_18 = 0x6a004c;
  iVar2 = -(int)(pcVar3 + (2 - (int)(param_2 + 1)));
  iVar6 = iVar2 - (int)param_2;
  do {
    cVar1 = *param_2;
    param_2[(int)(&stack0xffffffec + iVar6)] = cVar1;
    param_2 = param_2 + 1;
  } while (cVar1 != '\0');
  puVar5 = (undefined2 *)((int)&uStack_18 + iVar2 + 3);
  do {
    pcVar3 = (char *)((int)puVar5 + 1);
    puVar5 = (undefined2 *)((int)puVar5 + 1);
  } while (*pcVar3 != '\0');
  *puVar5 = 0x3d;
  iVar6 = 0;
  if (0 < *(int *)(param_1 + 8)) {
    do {
      *(undefined4 *)((int)&uStack_18 + iVar2) = 0x6a0092;
      iVar4 = FUN_0069ff20();
      if (iVar4 == 0) {
        local_8 = local_8 + 1;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(param_1 + 8));
  }
  return local_8;
}

