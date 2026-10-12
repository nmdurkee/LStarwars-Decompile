/* Ghidra pseudocode, not original source.
 * ev_dee7aab1ca5e5354a0f869482cb8068c6ad6aaead7d7bdba3544004762b43fb7
 * Entry: 0x6d6100; label: FUN_006d6100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006d6100(int param_1)

{
  if (param_1 < 1) {
    param_1 = 1;
  }
  else if (10 < param_1) {
    *(undefined1 *)(DAT_02975144 + 0x5d29) = 10;
    return;
  }
  *(char *)(DAT_02975144 + 0x5d29) = (char)param_1;
  return;
}

