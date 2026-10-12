/* Ghidra analysis pseudocode, not original source.
 * ev_fb3e2efa05f3fdcad8ac13641a8f1821f73d708273cedf9c40d68478f4bf822c
 * Entry: 0x575a30; label: FUN_00575a30
 */

void FUN_00575a30(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0x4698) != 0)) &&
     (iVar2 = 0, 0 < *(int *)(param_3 + 0x469c))) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(param_3 + 0x4698) + iVar3;
      FUN_0055aa60(*(undefined4 *)(param_3 + 0x2ac8),"Door_",iVar1,iVar1 + 0x40,0x40);
      FUN_00559ee0(param_1,param_2,0,*(int *)(param_3 + 0x4698) + iVar3);
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x128;
    } while (iVar2 < *(int *)(param_3 + 0x469c));
  }
  return;
}

