/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56e580; label: FUN_0056e580
 */

void FUN_0056e580(int param_1,int param_2)

{
  if ((((-1 < param_1) && (param_1 < *(int *)(PTR_DAT_008032c4 + 4))) && (-1 < param_2)) &&
     (param_2 < DAT_00951360)) {
    *(char *)(param_1 * 0x20 + 0xb + *(int *)PTR_DAT_008032c4) = (char)param_2;
  }
  return;
}

