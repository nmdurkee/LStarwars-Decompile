/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a620; label: FUN_0067a620
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067a620(void)

{
  if (DAT_0292fbf0 != 0) {
    return *(byte *)(DAT_0292fbf0 + 99) - 8;
  }
  return -1;
}

