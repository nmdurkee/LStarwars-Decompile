/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d9710; label: FUN_004d9710
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d9710(int param_1)

{
  if (DAT_00882406 != -1) {
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),(int)DAT_00882406,param_1 + 0x30);
  }
  if (DAT_00882408 != -1) {
    FUN_0064b370(DAT_00882408,param_1 + 0x30,1);
  }
  return;
}

