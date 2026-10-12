/* Ghidra pseudocode, not original source.
 * ev_a82e4e6157b5c05da4bf77128515088d4cb411e5fed9ff2f8222b3280f1d1bd7
 * Entry: 0x750330; label: FUN_00750330
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00750330(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_0080bba0;
  iVar3 = DAT_0080bb9c;
  if (-1 < DAT_0080bb9c) {
    piVar1 = (int *)(DAT_0080bba0 + 0x24 + DAT_0080bb9c * 0x28);
    *piVar1 = *piVar1 + -1;
    iVar3 = iVar2 + iVar3 * 0x28;
  }
  return iVar3;
}

