/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a71e0; label: FUN_005a71e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a71e0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    param_2[1] = 0;
    *param_2 = 0xffffffff;
    param_2[2] = 0;
    FUN_004ef6e0(param_2 + 3,0,0);
  }
  return;
}

