/* Ghidra analysis pseudocode, not original source.
 * ev_22c3a398bc6b82f0935d4925f42062b7808fee9576bfee9324dc2ce76fb66214
 * Entry: 0x742190; label: FUN_00742190
 */

float FUN_00742190(float param_1)

{
  if (param_1 < -16.0) {
    return -16.0;
  }
  if (15.96875 < param_1) {
    param_1 = 15.96875;
  }
  return param_1;
}

