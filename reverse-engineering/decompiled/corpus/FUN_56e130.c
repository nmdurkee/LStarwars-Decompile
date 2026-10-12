/* Ghidra analysis pseudocode, not original source.
 * ev_9c4a7344b4ed6999b1698de871080e88c37121f37ac9563577536a7a556549db
 * Entry: 0x56e130; label: FUN_0056e130
 */

void FUN_0056e130(int param_1,int param_2)

{
  if ((-1 < param_1) && (param_1 < *(int *)(PTR_DAT_008032c4 + 4))) {
    *(bool *)(param_1 * 0x20 + 8 + *(int *)PTR_DAT_008032c4) = param_2 != 0;
    FUN_0056e080();
    return;
  }
  return;
}

