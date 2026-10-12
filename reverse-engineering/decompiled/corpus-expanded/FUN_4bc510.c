/* Ghidra pseudocode, not original source.
 * ev_ec63a0996326cf703ee2b3a6fc0e0cae7d47cd208787877e90138bc554ba8dc2
 * Entry: 0x4bc510; label: FUN_004bc510
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004bc510(int param_1)

{
  DAT_0087a96c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"generator1");
  DAT_0087a970 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"generator2");
  DAT_0087a974 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"generator3");
  _DAT_0087a978 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"generator4");
  _DAT_0087a97c = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"generator5");
  _DAT_0087a980 = FUN_0055a020(*(undefined4 *)(param_1 + 0x2ac8),DAT_00802f54,"generator6");
  DAT_0087a7f0 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"ai_zam");
  DAT_0087b9c0 = 0;
  _DAT_0087b9c4 = 0;
  DAT_0087b9c0 = FUN_00440120(*(undefined4 *)(param_1 + 0x2ae8),"ai_zam");
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"CompletedB",0);
  return;
}

