/* Ghidra pseudocode, not original source.
 * ev_bef7beff20bbab7c70650c6f9f545113d8e67786c96c5ee03f6ff15c7c5049ec
 * Entry: 0x748490; label: FUN_00748490
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00748490(void)

{
  int *in_ECX;
  
  if ((*in_ECX != 0) && ((char)in_ECX[3] != '\0')) {
    FUN_006e85b0(*in_ECX);
    *in_ECX = 0;
  }
  return;
}

