/* Ghidra analysis pseudocode, not original source.
 * ev_11d21a68175a6094cc049e5bf26b7ff6a5a52d03a1d985acdd25f24f4e0bcb10
 * Entry: 0x613140; label: FUN_00613140
 */

void FUN_00613140(undefined4 param_1)

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

