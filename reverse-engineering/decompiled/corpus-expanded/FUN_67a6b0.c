/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a6b0; label: FUN_0067a6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_0067a6b0(void)

{
  if (DAT_02920ab0 != 0) {
    return (uint)*(byte *)(DAT_02920ab0 + 0x61);
  }
  return 0xffffffff;
}

