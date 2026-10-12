/* Ghidra pseudocode, not original source.
 * ev_f9aef5a40e02ce8ca7a9836408264f920f991102075b72e653cbe4eaab14c8b7
 * Entry: 0x580e10; label: FUN_00580e10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00580e10(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    FUN_004ef660(param_1,in_ECX[2] + in_ECX[1],2);
    if (*in_ECX != 0) {
      FUN_00621180(param_1);
    }
    in_ECX[2] = in_ECX[2] + 2;
  }
  return;
}

