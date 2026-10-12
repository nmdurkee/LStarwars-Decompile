/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5deb20; label: FUN_005deb20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005deb20(int *param_1,undefined4 param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  
  DAT_00973f94 = param_3;
  DAT_00973f98 = *param_1;
  *param_1 = *param_1 + param_3;
  DAT_00973f9c = *param_1 + 3U & 0xfffffffc;
  iVar2 = (*param_1 + 3U & 0xfffffffc) + param_3 * 0x24;
  *param_1 = iVar2;
  DAT_00973fa0 = iVar2 + 0xfU & 0xfffffff0;
  *param_1 = (*param_1 + 0xfU & 0xfffffff0) + param_3 * 0x20;
  iVar2 = 0;
  if (0 < param_3) {
    iVar3 = 0;
    do {
      *(undefined1 *)(DAT_00973f98 + iVar2) = 0;
      puVar1 = (undefined1 *)(iVar3 + 0x10 + DAT_00973fa0);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x20;
      *puVar1 = 0x84;
      *(undefined4 *)(puVar1 + 4) = 0;
      puVar1[1] = 4;
    } while (iVar2 < param_3);
  }
  return;
}

