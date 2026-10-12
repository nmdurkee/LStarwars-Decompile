/* Ghidra analysis pseudocode, not original source.
 * ev_2b6ca283a8ac7011eb105309a135b5adaaf9bfbb0074228736b4018ed27e76f8
 * Entry: 0x59b620; label: FUN_0059b620
 */

int FUN_0059b620(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  short *psVar3;
  short *psVar4;
  
  iVar1 = 0;
  if (0 < DAT_00956294) {
    psVar4 = (short *)(DAT_00956290 + 4);
    do {
      iVar2 = 0;
      psVar3 = psVar4;
      if (*(byte *)(psVar4 + 10) != 0) {
        do {
          if (*psVar3 == param_1) {
            if (param_2 == (int *)0x0) {
              return iVar1;
            }
            *param_2 = iVar2;
            return iVar1;
          }
          iVar2 = iVar2 + 1;
          psVar3 = psVar3 + 1;
        } while (iVar2 < (int)(uint)*(byte *)(psVar4 + 10));
      }
      iVar1 = iVar1 + 1;
      psVar4 = psVar4 + 0xe;
    } while (iVar1 < DAT_00956294);
  }
  if (param_2 != (int *)0x0) {
    *param_2 = -1;
  }
  return -1;
}

