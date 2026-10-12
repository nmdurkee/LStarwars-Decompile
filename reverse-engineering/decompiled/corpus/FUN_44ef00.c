/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44ef00; label: FUN_0044ef00
 */

undefined4
FUN_0044ef00(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar3 = 1;
  if (param_6 != 0) {
    if ((param_3 != 0) && (*(int **)(param_3 + 0xd0) != (int *)0x0)) {
      iVar5 = **(int **)(param_3 + 0xd0);
    }
    if ((param_5 != 0) && (iVar4 = 0, 0 < param_5)) {
      do {
        iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"FALSE");
        if (iVar1 == 0) {
          iVar3 = 0;
        }
        else {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
          if (iVar1 != 0) {
            if ((DAT_00923904 == (code *)0x0) ||
               (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
              iVar5 = 0;
            }
            else {
              iVar5 = *piVar2;
            }
          }
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
    if (iVar5 != 0) {
      *(uint *)(iVar5 + 0xeec) =
           *(uint *)(iVar5 + 0xeec) ^ (iVar3 << 4 ^ *(uint *)(iVar5 + 0xeec)) & 0x10;
      return 1;
    }
  }
  return 1;
}

