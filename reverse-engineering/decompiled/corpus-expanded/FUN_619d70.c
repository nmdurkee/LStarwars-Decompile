/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619d70; label: FUN_00619d70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619d70(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x150) < 4) {
    *(int *)(unaff_ESI + 0x14c) = *(int *)(unaff_ESI + 0x14c) + 1;
    iVar1 = FUN_004f1ff0((&DAT_02912118)[*(int *)(unaff_ESI + 0x150)]);
    if (iVar1 <= *(int *)(unaff_ESI + 0x14c)) {
      *(undefined4 *)(unaff_ESI + 0x14c) = 0;
    }
  }
  return;
}

