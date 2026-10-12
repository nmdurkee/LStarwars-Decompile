/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x7463e0; label: FUN_007463e0
 */

int FUN_007463e0(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = in_ECX[1];
  if (0 < iVar1) {
    if (*(char *)(iVar1 + -1 + *in_ECX) == '\0') {
      return *in_ECX;
    }
    if (in_ECX[2] < iVar1 + 1) {
      FUN_007484e0((iVar1 * 3 + 3) / 2);
    }
    *(undefined1 *)(*in_ECX + in_ECX[1]) = 0;
    in_ECX[1] = in_ECX[1] + 1;
  }
  return *in_ECX;
}

