/* Ghidra analysis pseudocode, not original source.
 * ev_988aedce7a102035a37775149c4794654cf73d0aa98e786da352e425eaa98523
 * Entry: 0x434930; label: FUN_00434930
 */

int FUN_00434930(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 == 0) {
    if (param_1 == -1) {
      return *(int *)(DAT_00926c20 + DAT_008806a0 * 4);
    }
  }
  else {
    iVar1 = *(int *)(param_2 + 0xcd0);
    if ((iVar1 == 0) || (**(int **)(iVar1 + 0x54) == -1)) {
      param_1 = (int)*(short *)(param_2 + 0x1064);
    }
    else {
      param_1 = (int)*(short *)(iVar1 + 0x1064);
    }
  }
  if (param_3 != 0) {
    if (param_1 == DAT_007f18e4) {
      if (DAT_0086e520 != '\0') {
        iVar1 = 0;
LAB_004349b6:
        FUN_004f1f10(param_3,&DAT_0086e500 + iVar1 * 0xe);
        iVar1 = 0xe;
        do {
          if (*(char *)(iVar1 + param_3) != ' ') {
            if (-1 < iVar1) {
              return param_3;
            }
            break;
          }
          iVar2 = iVar1 + -1;
          *(undefined1 *)(iVar1 + param_3) = 0;
          iVar1 = iVar2;
        } while (-1 < iVar2);
        FUN_004f1f10(param_3,&DAT_00755ba8);
        return param_3;
      }
    }
    else if ((param_1 == DAT_007f18e8) && (DAT_0086e558 != '\0')) {
      iVar1 = 1;
      goto LAB_004349b6;
    }
  }
  return *(int *)(DAT_00926c20 + *(int *)(param_1 * 0x4c + DAT_0093b274) * 4);
}

