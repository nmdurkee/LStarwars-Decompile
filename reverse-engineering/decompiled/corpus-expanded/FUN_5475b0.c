/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x5475b0; label: FUN_005475b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005475b0(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      return *(int *)(param_1 + 0xc) + 0x10;
    }
  }
  else if (*(int *)(param_2 + -8) != 0) {
    return *(int *)(param_2 + -8) + 0x10;
  }
  return 0;
}

