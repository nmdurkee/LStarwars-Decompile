/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x7463a0; label: FUN_007463a0
 */

void FUN_007463a0(undefined1 param_1)

{
  int *in_ECX;
  
  if (in_ECX[2] < in_ECX[1] + 1) {
    FUN_007484e0((in_ECX[1] * 3 + 3) / 2);
  }
  *(undefined1 *)(*in_ECX + in_ECX[1]) = param_1;
  in_ECX[1] = in_ECX[1] + 1;
  return;
}

