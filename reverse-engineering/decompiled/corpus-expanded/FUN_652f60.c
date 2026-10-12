/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652f60; label: FUN_00652f60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652f60(void)

{
  FUN_006989a0();
  FUN_00698440(1 - DAT_00810494);
  DAT_0081049a = 0xffff;
  DAT_00810492 = 0xffff;
  DAT_008104ac = 0;
  if (-1 < DAT_008104ae) {
    FUN_00652660((int)DAT_008104ae);
  }
  return;
}

