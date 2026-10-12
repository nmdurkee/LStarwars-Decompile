/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67c760; label: FUN_0067c760
 */

int FUN_0067c760(int param_1)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  
  iVar1 = -1;
  iVar3 = iVar1;
  if (param_1 != -1) {
    if (0 < *(int *)(DAT_0292fc68 + 0xa48c)) {
      psVar2 = (short *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4a);
      iVar3 = 0;
      while ((*(int *)(psVar2 + -5) == 0 || (*psVar2 != param_1))) {
        iVar3 = iVar3 + 1;
        psVar2 = psVar2 + 0x36;
        if (*(int *)(DAT_0292fc68 + 0xa48c) <= iVar3) {
          return iVar1;
        }
      }
    }
  }
  return iVar3;
}

