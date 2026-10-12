/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a5a0; label: FUN_0067a5a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0067a5a0(void)

{
  if (DAT_02947d88 != 0) {
    return (uint)*(byte *)(DAT_02947d88 + 0x60);
  }
  if (DAT_0292125e != '\0') {
    return (uint)DAT_02924b40;
  }
  return 0xffffffff;
}

