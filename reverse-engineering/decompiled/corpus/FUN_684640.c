/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x684640; label: FUN_00684640
 */

void FUN_00684640(int param_1)

{
  if (param_1 != -1) {
    FUN_0064ff80();
    FUN_006501a0();
    FUN_006500c0();
    *(undefined4 *)(param_1 * 0x330 + 0x300 + DAT_029620a4) = 0;
  }
  return;
}

