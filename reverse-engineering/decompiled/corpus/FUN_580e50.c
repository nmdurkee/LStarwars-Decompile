/* Ghidra analysis pseudocode, not original source.
 * ev_cf42e26bdd29ce594f9da2c695f01b0cbf0dbb26fec502101b142af0e3962cb1
 * Entry: 0x580e50; label: FUN_00580e50
 */

void FUN_00580e50(undefined4 param_1,int param_2,int param_3)

{
  int *in_ECX;
  int iVar1;
  int iVar2;
  
  if (in_ECX[1] != 0) {
    iVar1 = param_2 * param_3;
    FUN_004ef660(in_ECX[3] + in_ECX[1],param_1,iVar1);
    if (((*in_ECX != 0) && (1 < param_2)) && (iVar2 = in_ECX[3] + in_ECX[1], 0 < param_3)) {
      do {
        if (param_2 == 2) {
          FUN_00621180(iVar2);
        }
        else if (param_2 == 4) {
          FUN_00621190(iVar2);
        }
        iVar2 = iVar2 + param_2;
        param_3 = param_3 + -1;
      } while (param_3 != 0);
    }
    in_ECX[3] = in_ECX[3] + iVar1;
  }
  return;
}

