/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6be7f0; label: FUN_006be7f0
 */

int FUN_006be7f0(int param_1)

{
  int in_ECX;
  
  if ((-1 < param_1) && (param_1 < *(int *)(in_ECX + 0x24))) {
    return *(int *)(in_ECX + 8) + param_1 * 0x18;
  }
  return 0;
}

