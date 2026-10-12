/* Ghidra pseudocode, not original source.
 * ev_cede8c042851d77bd106acb1edcf2aeeffc4764a47601c9bcb205898acb43edb
 * Entry: 0x5ded40; label: FUN_005ded40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005ded40(void)

{
  if (DAT_00973fc4 != 0) {
    FUN_005d7230("<table   width=100%c height=20 bgcolor=#FF0000><tr><td><font face=arial size=+2></font></table>"
                 ,0x25);
    FUN_005d73e0();
    FUN_004f99e0(DAT_0096d938);
    DAT_00973fc4 = 0;
  }
  return;
}

