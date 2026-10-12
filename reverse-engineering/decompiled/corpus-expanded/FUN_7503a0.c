/* Ghidra pseudocode, not original source.
 * ev_a82e4e6157b5c05da4bf77128515088d4cb411e5fed9ff2f8222b3280f1d1bd7
 * Entry: 0x7503a0; label: FUN_007503a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_007503a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0080bbc4;
  iVar3 = DAT_0080bbc0;
  if (-1 < DAT_0080bbc0) {
    piVar1 = (int *)(DAT_0080bbc4 + 0x24 + DAT_0080bbc0 * 0x28);
    *piVar1 = *piVar1 + -1;
    iVar3 = iVar2 + iVar3 * 0x28;
  }
  return iVar3;
}

