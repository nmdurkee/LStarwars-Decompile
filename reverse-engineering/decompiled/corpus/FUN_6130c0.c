/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x6130c0; label: FUN_006130c0
 */

void FUN_006130c0(undefined4 param_1)

{
  int *in_ECX;
  
  if (in_ECX[1] != 0) {
    in_ECX[2] = in_ECX[2] + -2;
    FUN_004ef660(in_ECX[2] + in_ECX[1],param_1,2);
    if (*in_ECX != 0) {
      FUN_00621180(in_ECX[2] + in_ECX[1]);
    }
  }
  return;
}

