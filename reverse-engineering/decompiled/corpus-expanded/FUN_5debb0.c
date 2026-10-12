/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5debb0; label: FUN_005debb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005debb0(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < DAT_00973f94) {
    while (*(char *)(DAT_00973f98 + iVar2) != '\0') {
      iVar2 = iVar2 + 1;
      if (DAT_00973f94 <= iVar2) {
        return 0;
      }
    }
    if (iVar2 != -1) {
      iVar3 = iVar2 * 0x20 + DAT_00973fa0;
      *(undefined1 *)(DAT_00973f98 + iVar2) = 1;
      iVar1 = iVar2 * 0x24;
      *(undefined4 *)(iVar1 + 0x1c + DAT_00973f9c) = 0;
      *(int *)(iVar1 + DAT_00973f9c) = param_3 * 0x20000 + param_2;
      *(int *)(iVar1 + 4 + DAT_00973f9c) = iVar3;
      *(undefined4 *)(iVar1 + 0x18 + DAT_00973f9c) = 0;
      *(undefined2 *)(iVar1 + 0x20 + DAT_00973f9c) = 0;
      FUN_005de060();
      FUN_00603930(iVar3,param_1);
      return iVar2 + 1;
    }
  }
  return 0;
}

