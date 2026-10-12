/* Ghidra analysis pseudocode, not original source.
 * ev_537f31f6d7a7ebc324951952e862ea8d16fa2be695db959927eb9326274a35d3
 * Entry: 0x652de0; label: FUN_00652de0
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

