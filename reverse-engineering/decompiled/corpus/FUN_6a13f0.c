/* Ghidra analysis pseudocode, not original source.
 * ev_82e7b7710cce4f59c14fa183879226b2bf4ae3fcf6b271436ad9d0f6108f076a
 * Entry: 0x6a13f0; label: FUN_006a13f0
 */

undefined4 FUN_006a13f0(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_14 [20];
  
  iVar1 = *(int *)(param_1 + 0x1c);
  FUN_006a3940(local_14,*param_2,param_2[1]);
  iVar2 = FUN_006a3bb0(local_14,1);
  if (iVar2 != 0) {
    return 0xffffff79;
  }
  iVar3 = 0;
  for (iVar2 = *(int *)(iVar1 + 8); 1 < iVar2; iVar2 = iVar2 >> 1) {
    iVar3 = iVar3 + 1;
  }
  iVar2 = FUN_006a3bb0(local_14,iVar3);
  if (iVar2 != -1) {
    return *(undefined4 *)(iVar1 + **(int **)(iVar1 + 0x20 + iVar2 * 4) * 4);
  }
  return 0xffffff78;
}

