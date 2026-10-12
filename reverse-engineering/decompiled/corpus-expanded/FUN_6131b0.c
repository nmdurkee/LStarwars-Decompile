/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x6131b0; label: FUN_006131b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006131b0(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(param_1,in_ECX[2] + in_ECX[1],4);
    if (*in_ECX != 0) {
      FUN_00621190(param_1);
    }
    in_ECX[2] = in_ECX[2] + 4;
  }
  return;
}

