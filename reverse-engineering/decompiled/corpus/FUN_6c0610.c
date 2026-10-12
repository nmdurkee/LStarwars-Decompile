/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c0610; label: FUN_006c0610
 */

void FUN_006c0610(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 != -1) {
    iVar2 = (**(code **)(*in_ECX + 0x14))(0);
    while (iVar1 = iVar2, iVar1 != 0) {
      iVar2 = (**(code **)(*in_ECX + 0x14))(iVar1);
      if (*(short *)(iVar1 + 0x44) == param_1) {
        (**(code **)(*in_ECX + 0x1c))(iVar1,0);
      }
    }
  }
  return;
}

