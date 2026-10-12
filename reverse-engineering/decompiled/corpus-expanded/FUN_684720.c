/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x684720; label: FUN_00684720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

