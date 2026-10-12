/* Ghidra pseudocode, not original source.
 * ev_e37270f00559fec6395d344dad7372e88dd7c59f9ebe0b46a7132c9ac87d1215
 * Entry: 0x642470; label: FUN_00642470
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00642470(void)

{
  undefined4 *in_EAX;
  
  _DAT_009716e8 = *in_EAX;
  _DAT_009716ec = in_EAX[1];
  _DAT_009716f0 = in_EAX[2];
  FUN_005fca90();
  return;
}

