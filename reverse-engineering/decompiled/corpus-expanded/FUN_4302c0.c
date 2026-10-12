/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x4302c0; label: FUN_004302c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004302c0(int param_1)

{
  if (0.0 < *(float *)(param_1 + 0x20c)) {
    return 0;
  }
  return 1;
}

