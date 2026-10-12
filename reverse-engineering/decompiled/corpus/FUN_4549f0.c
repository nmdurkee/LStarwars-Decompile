/* Ghidra analysis pseudocode, not original source.
 * ev_8c5b0e575cc3a77a31b08f4844e5d8b5ee6e8018ce9d45deeeec0b9133723e57
 * Entry: 0x4549f0; label: FUN_004549f0
 */

undefined4
FUN_004549f0(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar4 = 0;
  local_4 = 1;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      iVar4 = **(int **)(param_3 + 0xd0);
    }
    if ((param_5 != 0) && (iVar3 = 0, 0 < param_5)) {
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar3 * 4),"FALSE");
        if (iVar1 == 0) {
          local_4 = 0;
        }
        else {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar3 * 4),"character=");
          if (iVar1 != 0) {
            if ((DAT_00923904 == (code *)0x0) ||
               (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
              iVar4 = 0;
            }
            else {
              iVar4 = *piVar2;
            }
          }
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_5);
    }
    if (iVar4 != 0) {
      if ((*(char *)(iVar4 + 0x7b5) == '<') || (*(int *)(iVar4 + 0xcd0) != 0)) {
        FUN_0055e4a0(iVar4,1);
      }
      *(uint *)(iVar4 + 0xef4) =
           *(uint *)(iVar4 + 0xef4) ^ (local_4 * 2 ^ *(uint *)(iVar4 + 0xef4)) & 2;
    }
  }
  return 1;
}

