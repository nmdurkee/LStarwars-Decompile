/* Ghidra pseudocode, not original source.
 * ev_a82e4e6157b5c05da4bf77128515088d4cb411e5fed9ff2f8222b3280f1d1bd7
 * Entry: 0x750590; label: FUN_00750590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00750590(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = &DAT_02868890;
  iVar2 = 0x200;
  do {
    if (*piVar1 != 0) {
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 0x12d;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}

