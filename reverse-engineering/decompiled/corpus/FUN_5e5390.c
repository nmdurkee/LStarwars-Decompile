/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e5390; label: FUN_005e5390
 */

int FUN_005e5390(int *param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  int local_8;
  uint local_4;
  
  iVar6 = 0;
  iVar3 = 0;
  local_8 = 0;
  local_4 = 0;
  if ((param_2 & 0x4000) == 0) {
    return *(int *)(*param_1 + param_2 * 4);
  }
  if (DAT_0096e570 != 0) {
    puVar7 = DAT_009716e4;
    do {
      iVar2 = *(int *)((DAT_0097157c - (int)DAT_009716e4) + (int)puVar7);
      if ((iVar2 != 0) && (-1 < *(int *)(iVar2 + 0x18))) {
        iVar5 = 0;
        pcVar4 = (char *)(*(int *)(param_1[2] + (param_2 & 0x3fff) * 4) + 8);
        do {
          iVar3 = local_8;
          if (*(char *)(iVar2 + 8 + iVar5) != *pcVar4) goto LAB_005e5433;
          iVar5 = iVar5 + 1;
          pcVar4 = pcVar4 + 1;
        } while (iVar5 < 0x10);
        if (local_4 < *puVar7) {
          local_8 = iVar6 + 1;
          iVar3 = local_8;
          local_4 = *puVar7;
        }
      }
LAB_005e5433:
      iVar6 = iVar6 + 1;
      puVar7 = puVar7 + 1;
    } while (iVar6 != DAT_0096e570);
    if (iVar3 != 0) {
      if ((0 < iVar3) && (iVar6 = *(int *)(DAT_0097157c + -4 + iVar3 * 4), iVar6 != 0)) {
        piVar1 = (int *)(iVar6 + 0x18);
        *piVar1 = *piVar1 + 1;
      }
      *(int *)(*param_1 + (param_2 & 0x3fff) * 4) = iVar3;
    }
  }
  return iVar3;
}

