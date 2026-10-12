/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6be8f0; label: FUN_006be8f0
 */

void FUN_006be8f0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) < *(int *)(in_ECX + 0x30)) {
    *(undefined4 *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 0x34) * 4) = param_1;
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
  }
  return;
}

