/* Ghidra analysis pseudocode, not original source.
 * ev_28935bb75220519b9cd6c8dd2893feffbabc6fed0a1828833445fdd6a861260d
 * Entry: 0x684720; label: FUN_00684720
 */

void FUN_00684720(int param_1,undefined1 param_2)

{
  if (param_1 != -1) {
    *(undefined1 *)(param_1 * 0x330 + 0x2fa + DAT_029620a4) = param_2;
    FUN_0064ff80();
    FUN_0064ffe0();
    FUN_006500c0();
    return;
  }
  return;
}

