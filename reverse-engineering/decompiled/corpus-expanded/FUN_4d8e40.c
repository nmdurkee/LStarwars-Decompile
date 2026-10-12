/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8e40; label: FUN_004d8e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

