/* Ghidra pseudocode, not original source.
 * ev_23fe0c900a66283c3d20cf72d3e92d7068463e5c92bfb1d0cb56e731534c3cac
 * Entry: 0x554870; label: FUN_00554870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00554870(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_3 + 0x46e0) != 0) &&
     (iVar2 = 0, *(char *)(*(int *)(param_3 + 0x128) + 0xf2) != '\0')) {
    iVar3 = 0;
    do {
      if (((*(byte *)(*(int *)(param_3 + 0x46e0) + 0xac + iVar3) & 1) != 0) &&
         (iVar1 = FUN_004f1ff0(*(int *)(param_3 + 0x46e0) + iVar3 + 0x40), iVar1 != 0)) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x46e0) + iVar3);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x304;
    } while (iVar2 < (int)(uint)*(byte *)(*(int *)(param_3 + 0x128) + 0xf2));
  }
  return;
}

