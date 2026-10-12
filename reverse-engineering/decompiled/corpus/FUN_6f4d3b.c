/* Ghidra analysis pseudocode, not original source.
 * ev_1492cb0b37f39299053b51444e553a69bb4676d2f076390f93a438e5515ce6e2
 * Entry: 0x6f4d3b; label: FUN_006f4d3b
 */

void FUN_006f4d3b(uint param_1,uint param_2)

{
  DAT_00829d70 = ~param_2 & DAT_00829d70 | param_1 & param_2;
  return;
}

