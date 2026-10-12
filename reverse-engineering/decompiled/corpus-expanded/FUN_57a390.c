/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a390; label: FUN_0057a390
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0057a390(int param_1)

{
  if (((param_1 != -1) && (DAT_00803b78 <= param_1)) && (param_1 <= DAT_00803b7c)) {
    return (DAT_00803b80 - DAT_00803b78) + param_1;
  }
  return param_1;
}

