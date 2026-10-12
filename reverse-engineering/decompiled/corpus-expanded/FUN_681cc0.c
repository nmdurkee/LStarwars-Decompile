/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x681cc0; label: FUN_00681cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00681cc0(int param_1)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (DAT_0292fc68 == (int *)0x0) {
    return 0;
  }
  if (0 < DAT_0292fc68[0x2923]) {
    psVar2 = (short *)(DAT_0292fc68[0x1a] + 0x4a);
    while ((*(int *)(psVar2 + -5) == 0 || (*psVar2 != param_1))) {
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x36;
      if (DAT_0292fc68[0x2923] <= iVar1) {
        return 0;
      }
    }
    if (iVar1 != -1) {
      return *DAT_0292fc68 + *(short *)(iVar1 * 0x6c + 0x48 + DAT_0292fc68[0x1a]) * 0x38;
    }
  }
  return 0;
}

