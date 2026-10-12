/* Ghidra pseudocode, not original source.
 * ev_e165dd79ce50f74ce872f7d9e4945159ab28a1cd27d81db1142f7150b3bed141
 * Entry: 0x62a2d0; label: FUN_0062a2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0062a2d0(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (DAT_02912e5c != 0) {
    FUN_00627820();
  }
  DAT_02912e68 = 0;
  DAT_02912e80 = param_1;
  for (puVar1 = DAT_02912e60; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1) {
    if ((code *)puVar1[3] != (code *)0x0) {
      (*(code *)puVar1[3])();
    }
  }
  DAT_02912e74 = FUN_005d5330();
  DAT_02912e78 = DAT_02912e74;
  FUN_00618c30();
  if ((DAT_0080f590 != 0) && (DAT_02912f18 == 0)) {
    DAT_02912f18 = FUN_004eef40(DAT_0080f590 * 0x118,
                                "d:\\projects\\legosagapc\\gameapi.saga\\edtools\\edui.cpp",0x821);
  }
  FUN_00629a90();
  if (param_2 != 0) {
    FUN_004f1f10(&DAT_02912a38,param_2);
    FUN_00617e80();
    DAT_02912e5c = 1;
    return;
  }
  DAT_02912a38 = 0;
  FUN_00617e80();
  DAT_02912e5c = 1;
  return;
}

