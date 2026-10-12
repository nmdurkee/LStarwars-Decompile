/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6be910; label: FUN_006be910
 */

void FUN_006be910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(in_ECX + 0x34)) {
    do {
      (**(code **)**(undefined4 **)(*(int *)(in_ECX + 0x10) + iVar1 * 4))
                (param_1,param_2,param_3,param_4,param_5,param_6);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(in_ECX + 0x34));
  }
  return;
}

