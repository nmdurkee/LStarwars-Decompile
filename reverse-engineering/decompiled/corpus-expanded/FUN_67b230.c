/* Ghidra pseudocode, not original source.
 * ev_96889fd8ad85600c7e65ee5089ba5210c04395d98557e70e963bff93f64702f9
 * Entry: 0x67b230; label: FUN_0067b230
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0067b230(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = DAT_0292186c;
  if (DAT_0292186c != 0) {
    *param_1 = *(undefined4 *)(DAT_0292186c + 0xa8);
    param_1[1] = *(undefined4 *)(iVar1 + 0xac);
    param_1[2] = *(undefined4 *)(iVar1 + 0xb0);
  }
  return;
}

