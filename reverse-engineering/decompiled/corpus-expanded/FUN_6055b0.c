/* Ghidra pseudocode, not original source.
 * ev_c781f6f2f7d78097ae9ff869f9175a8231755f2e9224784a2b208dfae7521271
 * Entry: 0x6055b0; label: FUN_006055b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006055b0(void)

{
  undefined4 *in_EAX;
  
  _DAT_009716e8 = *in_EAX;
  _DAT_009716ec = in_EAX[1];
  _DAT_009716f0 = in_EAX[2];
  _DAT_009868d8 = *in_EAX;
  _DAT_009868dc = in_EAX[1];
  DAT_009868c0 = DAT_009868c0 + 1;
  _DAT_009868e0 = in_EAX[2];
  _DAT_009868c4 = _DAT_009868c4 + 1;
  _DAT_009868d4 = 0;
  return;
}

