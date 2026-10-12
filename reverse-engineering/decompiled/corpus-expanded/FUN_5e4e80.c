/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e4e80; label: FUN_005e4e80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005e4e80(int param_1)

{
  undefined4 uVar1;
  int extraout_ECX;
  
  if ((0x17 < param_1) || (param_1 < 0)) {
    FUN_005c12e0();
    param_1 = extraout_ECX;
  }
  uVar1 = DAT_00973ff4;
  DAT_00973ff4 = param_1;
  return uVar1;
}

