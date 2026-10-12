/* Ghidra analysis pseudocode, not original source.
 * ev_92d4a724e69b6a04034eabfeaec94ac3aa2e75ce908c67016b571f650bed7677
 * Entry: 0x44fa90; label: FUN_0044fa90
 */

undefined4
FUN_0044fa90(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_4;
  
  iVar3 = 0;
  local_4 = 1;
  if (param_6 != 0) {
    if (((param_3 != 0) && (piVar2 = *(int **)(param_3 + 0xd0), piVar2 != (int *)0x0)) &&
       (*piVar2 != 0)) {
      iVar3 = *piVar2;
    }
    iVar4 = 0;
    iVar1 = 1;
    if (0 < param_5) {
      do {
        iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"character=");
        if (iVar1 == 0) {
          iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),"tag_to=");
          if (iVar1 == 0) {
            iVar1 = FUN_004f8b10(*(undefined4 *)(param_4 + iVar4 * 4),"FALSE");
            if (iVar1 == 0) {
              local_4 = 0;
            }
          }
          else if (DAT_00923904 != (code *)0x0) {
            (*DAT_00923904)(param_1,iVar1 + 7);
          }
        }
        else if ((DAT_00923904 == (code *)0x0) ||
                (piVar2 = (int *)(*DAT_00923904)(param_1,iVar1 + 10), piVar2 == (int *)0x0)) {
          iVar3 = 0;
        }
        else {
          iVar3 = *piVar2;
        }
        iVar4 = iVar4 + 1;
        iVar1 = local_4;
      } while (iVar4 < param_5);
    }
    if (iVar3 != 0) {
      *(uint *)(iVar3 + 0xeec) =
           *(uint *)(iVar3 + 0xeec) ^ (iVar1 << 0x1a ^ *(uint *)(iVar3 + 0xeec)) & 0x4000000;
      return 1;
    }
  }
  return 1;
}

