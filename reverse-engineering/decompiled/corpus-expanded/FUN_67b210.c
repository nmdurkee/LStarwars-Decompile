/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67b210; label: FUN_0067b210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0067b210(void)

{
  if (*(int *)(DAT_0292186c + 0x90) != 0) {
    return *(undefined1 *)(*(int *)(DAT_0292186c + 0x90) + 0x60);
  }
  return 0;
}

