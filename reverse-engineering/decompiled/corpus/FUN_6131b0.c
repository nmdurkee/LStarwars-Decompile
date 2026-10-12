/* Ghidra analysis pseudocode, not original source.
 * ev_f69f911d5171d962ef70197e58b92155315effa295abdaf930a75dc3063ba02e
 * Entry: 0x6131b0; label: FUN_006131b0
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

