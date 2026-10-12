/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x62a3a0; label: FUN_0062a3a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062a3a0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  _DAT_0080f514 = *param_3;
  _DAT_0080f518 = param_3[1];
  _DAT_0080f51c = param_3[2];
  _DAT_0080f520 = param_3[3];
  DAT_0080f528 = param_5;
  DAT_0080f52c = param_6;
  DAT_0080f524 = param_4;
  DAT_0080f530 = param_7;
  FUN_0062a2d0(param_1,param_2);
  return;
}

