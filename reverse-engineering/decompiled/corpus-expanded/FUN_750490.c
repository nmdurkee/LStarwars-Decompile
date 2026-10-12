/* Ghidra pseudocode, not original source.
 * ev_a82e4e6157b5c05da4bf77128515088d4cb411e5fed9ff2f8222b3280f1d1bd7
 * Entry: 0x750490; label: FUN_00750490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00750490(void)

{
  int iVar1;
  
  iVar1 = 0x1f;
  do {
    FUN_0060a580();
    iVar1 = iVar1 + -1;
  } while (-1 < iVar1);
  return;
}

