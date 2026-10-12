/* Ghidra pseudocode, not original source.
 * ev_7d1c367504044a8aaca3f86d1c78a9fb18090d1bc2abefa9dee9498b100eab75
 * Entry: 0x5951d0; label: FUN_005951d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005951d0(void)

{
  undefined4 *in_EAX;
  
  _DAT_009716e8 = *in_EAX;
  _DAT_009716ec = in_EAX[1];
  _DAT_009716f0 = in_EAX[2];
  FUN_005fca90();
  return;
}

