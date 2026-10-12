/* Ghidra pseudocode, not original source.
 * ev_a21f2a299e5366e10834c725088fc75c17a10a6d511d5a9cecc863d5aa4880c1
 * Entry: 0x611f60; label: FUN_00611f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00611f60(byte *param_1,int param_2,uint *param_3)

{
  byte bVar1;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    bVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_3 = (int)(short)(&DAT_02900838)[*param_3 & 0xff ^ (uint)bVar1] ^ *param_3 >> 8;
  }
  *param_3 = ~*param_3;
  return;
}

