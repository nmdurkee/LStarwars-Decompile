/* Ghidra analysis pseudocode, not original source.
 * ev_b9cc790e2909d179f3b1f9740b984f69e33873821bb15a6dd69be9c3f2a9fd10
 * Entry: 0x74b010; label: FUN_0074b010
 */

int FUN_0074b010(int param_1)

{
  int *in_ECX;
  
  if (*in_ECX == 0) {
    *in_ECX = param_1;
    return param_1;
  }
  if (in_ECX[1] != 0) {
    return 0;
  }
  in_ECX[1] = param_1;
  return param_1;
}

