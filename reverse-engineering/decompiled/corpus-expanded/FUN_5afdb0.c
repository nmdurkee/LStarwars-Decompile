/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afdb0; label: FUN_005afdb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005afdb0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0xffffffff;
    param_2[2] = 0;
  }
  return;
}

