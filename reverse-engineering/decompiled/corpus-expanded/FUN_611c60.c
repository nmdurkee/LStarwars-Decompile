/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611c60; label: FUN_00611c60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611c60(byte param_1,uint *param_2)

{
  *param_2 = (int)(short)(&DAT_02900838)[*param_2 & 0xff ^ (uint)param_1] ^ *param_2 >> 8;
  return;
}

