/* Ghidra pseudocode, not original source.
 * ev_ce5edc1561b77c28ba497ac7e0a731ad3290827c35b207bcfcd23dc4a7952c7a
 * Entry: 0x57a360; label: FUN_0057a360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 * FUN_0057a360(int param_1)

{
  if (((DAT_00951bb8 != 0) && (-1 < param_1)) && (param_1 < DAT_00951bbc)) {
    return *(undefined1 **)(DAT_00951bb8 + 4 + param_1 * 8);
  }
  return &DAT_007516c0;
}

