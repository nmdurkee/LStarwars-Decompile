/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x6997a0; label: FUN_006997a0
 */

int FUN_006997a0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if (in_ECX == 0) {
    return 0;
  }
  cVar1 = FUN_00699260(3);
  if (cVar1 != '\0') {
    return 2;
  }
  if ((*(int *)(in_ECX + 8) != 2) && ((*(int *)(in_ECX + 8) != 3 || (*(int *)(in_ECX + 0xc) == 0))))
  {
    iVar2 = FUN_00699770();
    return (-(uint)(iVar2 != 0) & 0xfffffffe) + 2;
  }
  return 1;
}

