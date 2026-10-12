/* Ghidra analysis pseudocode, not original source.
 * ev_22daf69c4a948facb72037c7642983d59ec5bfdbe162bc8de16c186a70e458b1
 * Entry: 0x43cc30; label: FUN_0043cc30
 */

void FUN_0043cc30(int *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    _memset((void *)param_1[1],0,*param_1 * 0xa8);
    iVar2 = 0;
    if (0 < *param_1) {
      iVar1 = 0;
      do {
        FUN_004f1310(param_1 + 2,param_1[1] + iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0xa8;
      } while (iVar2 < *param_1);
    }
  }
  return;
}

