/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x580dd0; label: FUN_00580dd0
 */

void FUN_00580dd0(undefined4 param_1)

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

