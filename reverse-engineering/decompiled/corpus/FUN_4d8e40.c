/* Ghidra analysis pseudocode, not original source.
 * ev_469f0313f1021f0e4bd926e538674038e4b9c059f1b4f78e0c32d78ee9f9f283
 * Entry: 0x4d8e40; label: FUN_004d8e40
 */

void FUN_004d8e40(int param_1)

{
  if (DAT_00882406 != -1) {
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)DAT_00882406);
  }
  if (DAT_00882408 != -1) {
    FUN_0064b370(DAT_00882408);
  }
  FUN_00549f10();
  FUN_00549bb0(0,0x3f400000,0x3f800000,0x3f800000);
  FUN_00681f40("Explode1",param_1 + 0x80);
  return;
}

