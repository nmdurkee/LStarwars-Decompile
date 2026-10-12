/* Ghidra analysis pseudocode, not original source.
 * ev_ad9cc5423de1ab1dd38d346f275414df9adbe91527778a2cec40e67e5c2b6778
 * Entry: 0x473eb0; label: FUN_00473eb0
 */

void FUN_00473eb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0x5074), piVar1 != (int *)0x0)) &&
     (iVar3 = 0, 0 < *piVar1)) {
    iVar4 = 0;
    do {
      iVar2 = FUN_004f1ff0(piVar1[3] + 0x40 + iVar4);
      if (iVar2 != 0) {
        FUN_00559ee0(param_1,param_2,0,*(int *)(*(int *)(param_3 + 0x5074) + 0xc) + iVar4);
      }
      piVar1 = *(int **)(param_3 + 0x5074);
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0xa0;
    } while (iVar3 < *piVar1);
  }
  return;
}

