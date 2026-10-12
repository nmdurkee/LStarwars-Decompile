/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619dd0; label: FUN_00619dd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619dd0(void)

{
  int unaff_ESI;
  
  if ((*(byte *)(unaff_ESI + 0x164) & 2) != 0) {
    FUN_004f1f40(&DAT_02912ed8,unaff_ESI + 0x4c,0x40);
    *(undefined1 *)(unaff_ESI + 0x8b) = 0;
  }
  return;
}

