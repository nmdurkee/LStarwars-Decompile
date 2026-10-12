/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d71d0; label: FUN_005d71d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005d71d0(int param_1)

{
  if (DAT_00971890 < DAT_0096e574 || param_1 != 0) {
    FUN_004f0750(DAT_00973968,&DAT_009720b8);
    DAT_0096e574 = &DAT_009720b8;
    DAT_00971890 = &DAT_00972cb8;
  }
  return;
}

