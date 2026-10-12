/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x490b70; label: FUN_00490b70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_00490b70(int param_1)

{
  return *(byte *)(param_1 + 0x94) >> 1 & 1;
}

