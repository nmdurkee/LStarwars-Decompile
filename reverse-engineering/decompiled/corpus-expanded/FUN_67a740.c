/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a740; label: FUN_0067a740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067a740(undefined4 *param_1,undefined4 param_2)

{
  if (DAT_0292fc64 < 0x10) {
    (&DAT_02921660)[DAT_0292fc64 * 4] = *param_1;
    (&DAT_02921664)[DAT_0292fc64 * 4] = param_1[1];
    (&DAT_02921668)[DAT_0292fc64 * 4] = param_1[2];
    (&DAT_0292166c)[DAT_0292fc64 * 4] = param_2;
    DAT_0292fc64 = DAT_0292fc64 + 1;
  }
  return;
}

