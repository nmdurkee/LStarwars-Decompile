/* Ghidra analysis pseudocode, not original source.
 * ev_6dd3c36930770dc91587d8e9f0315de295532c3384b93e99878ade04445159cc
 * Entry: 0x50b850; label: FUN_0050b850
 */

void FUN_0050b850(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)

{
  DAT_00801598 = param_1;
  if (5 < param_1) {
    DAT_00801598 = 6;
  }
  DAT_00921e70 = param_2;
  DAT_00921e68 = param_4;
  DAT_00921e60 = param_3;
  DAT_00921e64 = FUN_004eef40(param_4 + 4,
                              "d:\\projects\\legosagapc\\gameapi.saga\\gui\\gamemenu\\apisave.c",
                              0x6d);
  DAT_00921e6c = param_5;
  DAT_00921e74 = param_6;
  return;
}

