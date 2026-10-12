/* Ghidra analysis pseudocode, not original source.
 * ev_71ff980de6cd2ba2d40ffdcea863fac96239c7d224aa9f068f740db15dbd9919
 * Entry: 0x52d220; label: FUN_0052d220
 */

undefined4
FUN_0052d220(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((((param_3 == 0) || (*(int **)(param_3 + 0xd0) == (int *)0x0)) ||
      (**(int **)(param_3 + 0xd0) == 0)) ||
     ((*(int *)(param_3 + 0x158) == 0 || (*(int *)(param_3 + 0x15c) == 0)))) {
    return 1;
  }
  if (param_6 != 0) {
    iVar4 = 0;
    *(undefined4 *)(param_2 + 0x6c) = *(undefined4 *)(param_2 + 0xa4);
    if (0 < param_5) {
      do {
        if (((DAT_009238b0 == (code *)0x0) ||
            (iVar1 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar4 * 4),param_3 + 0x13f),
            iVar1 == 0)) &&
           (iVar1 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar4 * 4),&DAT_0075782c), iVar1 != 0)) {
          iVar4 = iVar4 + 1;
          iVar2 = FUN_004f1ff0(&DAT_0075782c);
          uVar3 = FUN_0051ac10(param_1,iVar2 + 1 + iVar1);
          *(undefined4 *)(param_2 + 0x6c) = uVar3;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < param_5);
    }
  }
  if (*(int *)(param_2 + 0x6c) == 0) {
    return 0;
  }
  *(int *)(param_3 + 0x1e4) = *(int *)(param_2 + 0x6c) + 0x10;
  return 1;
}

