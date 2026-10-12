/* Ghidra pseudocode, not original source.
 * ev_5667e5448bcdd65d51b4846c6b703f5dc39afd73914fbe1d2cb4bfca537c9b4f
 * Entry: 0x6d3750; label: FUN_006d3750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006d3750(int param_1,int param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  
  iVar1 = 0;
  if (0 < param_2) {
    psVar2 = (short *)(param_1 + 0x5e);
    do {
      if ((*(int *)(param_3 + 0x40) == *(int *)(psVar2 + -0xf)) &&
         (*(short *)(param_3 + 0x5e) == *psVar2)) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      psVar2 = psVar2 + 0x4e;
    } while (iVar1 < param_2);
  }
  return -1;
}

