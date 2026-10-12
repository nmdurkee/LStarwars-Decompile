/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x694d50; label: FUN_00694d50
 */

void FUN_00694d50(undefined4 param_1,float param_2)

{
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    if (param_2 != 0.0) {
      *(float *)(in_ECX + 0x1a4) = 1.0 / param_2;
      *(undefined4 *)(in_ECX + 0x1a0) = param_1;
      return;
    }
    *(undefined4 *)(in_ECX + 0x1a0) = param_1;
    *(undefined4 *)(in_ECX + 0x19c) = param_1;
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
  }
  return;
}

