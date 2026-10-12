/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a690; label: FUN_0067a690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0067a690(void)

{
  if (DAT_0292182c != 0) {
    return (uint)*(byte *)(DAT_0292182c + 0x60);
  }
  return 0xffffffff;
}

