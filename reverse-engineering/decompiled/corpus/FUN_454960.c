/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x454960; label: FUN_00454960
 */

undefined4
FUN_00454960(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_6 != 0) && (param_3 != 0)) &&
      (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (((*piVar1 != 0 && (iVar2 = *piVar1, iVar2 != 0)) && (iVar4 = 0, 0 < param_5)))) {
    do {
      iVar3 = FUN_004f8b10(&DAT_00758430,*(undefined4 *)(param_4 + iVar4 * 4));
      if (iVar3 == 0) {
        *(uint *)(iVar2 + 0xef0) = *(uint *)(iVar2 + 0xef0) | 0x40000000;
      }
      else {
        iVar3 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"false");
        if (iVar3 != 0) {
          *(uint *)(iVar2 + 0xef0) = *(uint *)(iVar2 + 0xef0) & 0xbfffffff;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_5);
  }
  return 1;
}

