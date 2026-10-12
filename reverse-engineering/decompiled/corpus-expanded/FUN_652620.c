/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652620; label: FUN_00652620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00652620(void)

{
  _DAT_008104a4 = 0;
  if (DAT_00810490 == 0xb) {
    DAT_00810496 = 0xffff;
    return;
  }
  DAT_0081049a = 0xffff;
  DAT_00810492 = 0xffff;
  DAT_008104a0 = 0;
  return;
}

