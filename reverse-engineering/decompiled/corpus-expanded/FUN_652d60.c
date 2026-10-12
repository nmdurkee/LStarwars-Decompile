/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652d60; label: FUN_00652d60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652d60(void)

{
  if ((((DAT_02962038 == 0) && (DAT_02962034 == 0)) && (DAT_00810db0 != -1)) &&
     (((DAT_00810490 != 0xb && (DAT_00810490 != 0xc)) && (DAT_00810490 != 0xd)))) {
    FUN_006989a0();
    FUN_00698440((int)DAT_00810494);
    if ((int)DAT_00810490 - 5U < 6) {
      FUN_00698440(1 - DAT_00810494);
    }
  }
  DAT_008104a1 = 0;
  return;
}

