/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a670; label: FUN_0067a670
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0067a670(void)

{
  if (DAT_0292fd44 != 0) {
    return (uint)*(byte *)(DAT_0292fd44 + 0x61);
  }
  return 0xffffffff;
}

