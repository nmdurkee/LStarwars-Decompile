/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619d40; label: FUN_00619d40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619d40(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x150) < 4) {
    piVar1 = (int *)(unaff_ESI + 0x14c);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 < 0) {
      iVar2 = FUN_004f1ff0((&DAT_02912118)[*(int *)(unaff_ESI + 0x150)]);
      *(int *)(unaff_ESI + 0x14c) = iVar2 + -1;
    }
  }
  return;
}

