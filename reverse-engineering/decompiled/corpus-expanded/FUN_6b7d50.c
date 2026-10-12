/* Ghidra pseudocode, not original source.
 * ev_4ce08863d5da0fee7b6d57af0905edeb9afe2ef672ddcc937a67468fc554aef4
 * Entry: 0x6b7d50; label: FUN_006b7d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b7d50(void)

{
  int unaff_ESI;
  
  FUN_005b3b30();
  *(undefined4 *)(unaff_ESI + 0xc) = 0x3f800000;
  return;
}

