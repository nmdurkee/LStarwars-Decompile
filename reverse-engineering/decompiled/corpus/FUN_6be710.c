/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6be710; label: FUN_006be710
 */

int FUN_006be710(int param_1)

{
  int in_ECX;
  
  if ((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0x1c))) {
    return *(int *)(in_ECX + 4) + param_1 * 0xc;
  }
  return 0;
}

