/* Ghidra pseudocode, not original source.
 * ev_36c567c8b03fa9be6305a90618e5976b2395159d59c428aaf9f1abc99d465ca0
 * Entry: 0x65b6c0; label: FUN_0065b6c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065b6c0(int param_1,undefined1 param_2)

{
  if (param_1 != 0) {
    FUN_004f1f10(&DAT_02962118,param_1);
    DAT_0292118a = param_2;
    return;
  }
  DAT_02962118 = 0;
  DAT_0292118a = param_2;
  return;
}

