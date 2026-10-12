/* Ghidra pseudocode, not original source.
 * ev_f8ea80cbfae9cb61d37d4e579d4a737819a41489e1a74b58bc2061b157f40247
 * Entry: 0x652de0; label: FUN_00652de0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00652de0(void)

{
  if (((DAT_02962038 == 0) || (DAT_02962034 == 0)) && (DAT_00810db0 != -1)) {
    if (DAT_00810498 < 0x19) {
      DAT_008104a1 = 1;
      return;
    }
    if (((DAT_00810490 != 0xb) && (DAT_00810490 != 0xc)) && (DAT_00810490 != 0xd)) {
      FUN_00698420((int)DAT_00810494);
      if ((int)DAT_00810490 - 5U < 6) {
        FUN_00698420(1 - DAT_00810494);
      }
    }
  }
  return;
}

