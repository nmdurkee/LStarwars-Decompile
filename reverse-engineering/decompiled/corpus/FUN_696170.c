/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x696170; label: FUN_00696170
 */

undefined4 FUN_00696170(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    uVar1 = FUN_00694320(param_1,param_2);
    uVar1 = FUN_00694240(param_1,uVar1);
    return uVar1;
  }
  return 0;
}

