/* Ghidra pseudocode, not original source.
 * ev_96df89c4daae28ff35d834560256e783041bc073304993e474c02e03eab098bd
 * Entry: 0x4915a0; label: FUN_004915a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004915a0(void)

{
  if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_00951b94) {
    return (int)DAT_0087b460;
  }
  return -1;
}

