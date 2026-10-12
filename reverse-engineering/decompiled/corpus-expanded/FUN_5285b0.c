/* Ghidra pseudocode, not original source.
 * ev_856f9c42d20ec6ba6350b0d1cce9335bfe45cee30263bcd63df252d3cb890b58
 * Entry: 0x5285b0; label: FUN_005285b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005285b0(void)

{
  void *unaff_ESI;
  
  if (unaff_ESI != (void *)0x0) {
    FUN_004f1410(DAT_009238e4 + 0x371a4);
    _memset(unaff_ESI,0,0xac);
    FUN_004f1310(DAT_009238e4 + 0x3719c);
  }
  return;
}

