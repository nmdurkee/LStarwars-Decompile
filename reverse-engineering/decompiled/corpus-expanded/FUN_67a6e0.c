/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a6e0; label: FUN_0067a6e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0067a6e0(void)

{
  if (((DAT_0292fc68 != (int *)0x0) && (DAT_02961fdc != -1)) &&
     (*(int *)(*DAT_0292fc68 + 0x2c + DAT_02961fdc * 0x38) == 1)) {
    return (int)*(short *)(*DAT_0292fc68 + DAT_02961fdc * 0x38 + 0x30);
  }
  return -1;
}

