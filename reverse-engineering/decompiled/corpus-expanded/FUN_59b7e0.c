/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59b7e0; label: FUN_0059b7e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0059b7e0(int param_1)

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
  return -1;
}

