/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e7c90; label: FUN_004e7c90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004e7c90(int param_1)

{
  if (DAT_00951b50 == 0) {
    _memset(&DAT_0088a410,0,0xc0);
  }
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"ShowHearts",0);
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_007f8cc4,"force3");
  return;
}

