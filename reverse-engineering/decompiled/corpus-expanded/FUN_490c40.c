/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490c40; label: FUN_00490c40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00490c40(undefined4 param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
    param_2[1] = 0xffffffff;
    param_2[2] = 0xffffffff;
  }
  return;
}

