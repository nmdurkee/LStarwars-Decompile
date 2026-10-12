/* Ghidra pseudocode, not original source.
 * ev_b0e64e2dfe3722016930d355629873abe6bb90a38d3b309aad52c0d35b9c8629
 * Entry: 0x50b850; label: FUN_0050b850
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

