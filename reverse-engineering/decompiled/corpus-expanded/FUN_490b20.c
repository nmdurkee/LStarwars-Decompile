/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490b20; label: FUN_00490b20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00490b20(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *param_1 + 0x58;
  }
  return 0;
}

