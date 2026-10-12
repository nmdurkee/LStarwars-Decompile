/* Ghidra pseudocode, not original source.
 * ev_8f65dc07aca5ead6ac5de11150d58420913a4b73213f2c7b5665ab54197e4ce2
 * Entry: 0x6846a0; label: FUN_006846a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006846a0(int param_1)

{
  if (param_1 != -1) {
    FUN_0064ff80();
    FUN_006501a0();
    FUN_006500c0();
    FUN_0064ffe0();
    *(undefined4 *)(param_1 * 0x330 + 0x300 + DAT_029620a4) = 0;
  }
  return;
}

