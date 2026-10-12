/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x613100; label: FUN_00613100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00613100(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(in_ECX[3] + in_ECX[1],param_1,2);
    if (*in_ECX != 0) {
      FUN_00621180(in_ECX[3] + in_ECX[1]);
    }
    in_ECX[3] = in_ECX[3] + 2;
  }
  return;
}

