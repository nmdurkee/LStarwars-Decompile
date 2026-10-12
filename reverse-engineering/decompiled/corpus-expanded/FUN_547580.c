/* Ghidra pseudocode, not original source.
 * ev_3142b78bb26b296d5a5ace8e326a7bee627125b5aa8d8d8928c83f6a565e0b24
 * Entry: 0x547580; label: FUN_00547580
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00547580(int param_1,int param_2)

{
  if (param_2 == 0) {
    if (*(int *)(param_1 + 8) != 0) {
      return *(int *)(param_1 + 8) + 0x10;
    }
  }
  else if (*(int *)(param_2 + -0xc) != 0) {
    return *(int *)(param_2 + -0xc) + 0x10;
  }
  return 0;
}

