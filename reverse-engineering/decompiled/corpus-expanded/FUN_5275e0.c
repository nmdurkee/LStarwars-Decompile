/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x5275e0; label: FUN_005275e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005275e0(void)

{
  void *unaff_ESI;
  
  if (unaff_ESI != (void *)0x0) {
    FUN_004f1410(DAT_009238e4 + 0x43814);
    _memset(unaff_ESI,0,0x4c);
    FUN_004f1310(DAT_009238e4 + 0x4380c);
  }
  return;
}

