/* Ghidra pseudocode, not original source.
 * ev_c4ffb1da974488f0d31d138643195e5dda1d4714e1fef5a95fdc86fcf60e8c52
 * Entry: 0x633f00; label: FUN_00633f00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00633f00(void)

{
  undefined4 *in_EAX;
  
  _DAT_009716e8 = *in_EAX;
  _DAT_009716ec = in_EAX[1];
  _DAT_009716f0 = in_EAX[2];
  FUN_005fca90();
  return;
}

