/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x580e10; label: FUN_00580e10
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

