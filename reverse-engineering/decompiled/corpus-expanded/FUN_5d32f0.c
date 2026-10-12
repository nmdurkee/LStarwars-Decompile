/* Ghidra pseudocode, not original source.
 * ev_feeb0d300fc0a1ec823458f778250bd56b5f3fc24779efc17b7484c96bfb9aef
 * Entry: 0x5d32f0; label: FUN_005d32f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d32f0(undefined4 *param_1)

{
  for (; param_1 != (undefined4 *)0x0; param_1 = (undefined4 *)*param_1) {
    if (param_1[5] != 0) {
      FUN_005d2d10(param_1[5]);
    }
  }
  return;
}

