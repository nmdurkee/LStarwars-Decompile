/* Ghidra pseudocode, not original source.
 * ev_df72e9ec6d097d98265581ff35a2e461cddfe69d3931fceba3802c9eedcc8d52
 * Entry: 0x6418e0; label: FUN_006418e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006418e0(float param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  _DAT_029139d8 = _DAT_029139d8 - param_1;
  if (_DAT_029139d8 < 0.0) {
    _DAT_029139d8 = _DAT_029139d8 + _DAT_0080ff38;
  }
  if (DAT_0291397c == 0) {
    uVar1 = FUN_0063b2d0(param_1,param_2);
    return uVar1;
  }
  if (DAT_0291397c == 2) {
    uVar1 = FUN_0063bdf0(param_1);
    return uVar1;
  }
  if (DAT_0291397c != 1) {
    return 1;
  }
  uVar1 = FUN_00641690(param_1);
  return uVar1;
}

