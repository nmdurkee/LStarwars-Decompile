/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5b0070; label: FUN_005b0070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_005b0070(int *param_1,int param_2)

{
  if ((*(byte *)(*param_1 + 0x38) & 1) == 0) {
    return false;
  }
  return param_2 == *(int *)(*param_1 + 0x34);
}

