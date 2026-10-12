/* Ghidra analysis pseudocode, not original source.
 * ev_c9fa25cc79717ad47e0beb6e0964d9456c9021d00a3c9a64cb36b68ef15e0051
 * Entry: 0x6c0880; label: FUN_006c0880
 */

undefined4 FUN_006c0880(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_004fb550(*(undefined4 *)(in_ECX + 0x198),param_1,param_2 * param_3);
  if (((*(int *)(in_ECX + 0xc) != 0) && (1 < param_2)) && (0 < param_3)) {
    do {
      if (param_2 == 2) {
        FUN_00621180(param_1);
      }
      else if (param_2 == 4) {
        FUN_00621190(param_1);
      }
      param_1 = param_1 + param_2;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return uVar1;
}

