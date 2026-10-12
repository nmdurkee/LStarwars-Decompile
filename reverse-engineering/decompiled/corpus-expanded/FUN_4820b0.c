/* Ghidra pseudocode, not original source.
 * ev_6d95b912f1db8f5f9ae5a1d448774b8e294221a9d492d15be8ca5acea434db46
 * Entry: 0x4820b0; label: FUN_004820b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004820b0(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0xffffffff;
    param_2[1] = 0xffffffff;
    param_2[2] = 0xffffffff;
    param_2[3] = 0xffffffff;
    param_2[4] = 0xffffffff;
    param_2[5] = 0xffffffff;
    param_2[6] = 0xffffffff;
    param_2[7] = 0xffffffff;
  }
  return;
}

