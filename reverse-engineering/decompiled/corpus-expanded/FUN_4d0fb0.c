/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d0fb0; label: FUN_004d0fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004d0fb0(int *param_1,int param_2)

{
  if (param_1 != (int *)0x0) {
    *(bool *)(*param_1 + 0x47) = param_2 != 0;
  }
  return;
}

