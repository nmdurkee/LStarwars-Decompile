/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x430280; label: FUN_00430280
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00430280(int param_1,float param_2)

{
  param_2 = *(float *)(param_1 + 0x20c) - param_2;
  *(float *)(param_1 + 0x20c) = param_2;
  if (param_2 <= 0.0) {
    *(undefined4 *)(param_1 + 0x1b0) = 0;
    *(undefined4 *)(param_1 + 0x1d0) = 0;
  }
  return;
}

