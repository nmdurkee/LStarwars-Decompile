/* Ghidra analysis pseudocode, not original source.
 * ev_8c0b129907146dba16e0c839f08bc31abcfde84bb6f318465034d474a072817c
 * Entry: 0x410050; label: FUN_00410050
 */

int FUN_00410050(void)

{
  int iVar1;
  int *piVar2;
  int in_EDX;
  
  iVar1 = 0;
  piVar2 = (int *)(in_EDX + 0x565e0);
  do {
    if (*piVar2 == 0) {
      return iVar1 * 0x130 + 0x564d0 + in_EDX;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 0x4c;
  } while (iVar1 < 0x60);
  return 0;
}

