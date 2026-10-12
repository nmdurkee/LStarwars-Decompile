/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afe70; label: FUN_005afe70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005afe70(int *param_1)

{
  if (param_1 == (int *)0x0) {
    return 0;
  }
  return *param_1 + 0x10;
}

