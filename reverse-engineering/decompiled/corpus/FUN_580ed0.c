/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x580ed0; label: FUN_00580ed0
 */

void FUN_00580ed0(int param_1,int param_2,int param_3)

{
  int *in_ECX;
  int iVar1;
  
  if (in_ECX[1] != 0) {
    iVar1 = param_2 * param_3;
    FUN_004ef660(param_1,in_ECX[2] + in_ECX[1],iVar1);
    if (((*in_ECX != 0) && (1 < param_2)) && (0 < param_3)) {
      do {
        if (param_2 == 2) {
          FUN_00621180(param_1);
        }
        else if (param_2 == 4) {
          FUN_00621190(param_1);
        }
        param_1 = param_1 + param_2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    in_ECX[2] = in_ECX[2] + iVar1;
  }
  return;
}

