/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67a640; label: FUN_0067a640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067a640(float *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0292fbf0;
  if (DAT_0292fbf0 != 0) {
    *param_1 = *(float *)(DAT_0292fbf0 + 0x24) - *(float *)(DAT_0292fbf0 + 0x18);
    param_1[1] = *(float *)(iVar1 + 0x28) - *(float *)(iVar1 + 0x1c);
    param_1[2] = *(float *)(iVar1 + 0x2c) - *(float *)(iVar1 + 0x20);
  }
  return;
}

