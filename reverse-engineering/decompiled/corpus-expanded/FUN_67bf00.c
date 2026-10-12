/* Ghidra pseudocode, not original source.
 * ev_32eeff13403f2b0416c64559eab438b182c65995ce85fb3a27dd5c4451fc4fee
 * Entry: 0x67bf00; label: FUN_0067bf00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0067bf00(int param_1)

{
  short *psVar1;
  int iVar2;
  
  if (0 < *(int *)(DAT_0292fc68 + 0xa48c)) {
    psVar1 = (short *)(*(int *)(DAT_0292fc68 + 0x68) + 0x4a);
    iVar2 = 0;
    while ((*(int *)(psVar1 + -5) == 0 || (*psVar1 != param_1))) {
      iVar2 = iVar2 + 1;
      psVar1 = psVar1 + 0x36;
      if (*(int *)(DAT_0292fc68 + 0xa48c) <= iVar2) {
        return 0;
      }
    }
    if (iVar2 != -1) {
      return 1;
    }
  }
  return 0;
}

