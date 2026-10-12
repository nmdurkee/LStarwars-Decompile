/* Ghidra analysis pseudocode, not original source.
 * ev_f9fdf251b645beb492fc1c60a340a2dfddcd81399c22694a11250778b8584a81
 * Entry: 0x695170; label: FUN_00695170
 */

void FUN_00695170(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (in_ECX == 0) {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 0;
    }
  }
  else {
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *(undefined4 *)(in_ECX + 0x1dc);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(in_ECX + 0x1e0);
      return;
    }
  }
  return;
}

