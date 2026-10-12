/* Ghidra pseudocode, not original source.
 * ev_1794ca22652287671530b7d2e638694f2898180de05a8f26cc5ace6b6aa326ae
 * Entry: 0x4d1090; label: FUN_004d1090
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004d1090(int *param_1)

{
  if ((*(char *)(*param_1 + 0x46) != '\0') && (*(char *)(*param_1 + 0x47) != '\0')) {
    return 1;
  }
  return 0;
}

