/* Ghidra pseudocode, not original source.
 * ev_f6678a28cc19d550655313a6a6f4f7bb8e44fc9612bb24799d4de398af21bc4a
 * Entry: 0x4c8d90; label: FUN_004c8d90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c8d90(void)

{
  DAT_0088a530 = 0;
  FUN_00433120();
  DAT_0087aa5c = FUN_005aac00(DAT_0095df4c,"SpeedersToKill",0);
  DAT_0087aa60 = FUN_005aac00(DAT_0095df4c,"SpeedersKilled",0);
  _DAT_0087aa64 = FUN_005aac00(DAT_0095df4c,"Stage",0);
  DAT_0087aa68 = FUN_005aac00(DAT_0095df4c,"Phase",0);
  DAT_0087aa6c = FUN_005aac00(DAT_0095df4c,"KeepPlayersOnSpeeders",0);
  _DAT_0087aa70 = FUN_005aac00(DAT_0095df4c,"SpeederMode",0);
  DAT_007fcd84 = 1;
  return;
}

