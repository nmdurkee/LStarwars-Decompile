/* Ghidra pseudocode, not original source.
 * ev_32a2dc35cb5c8cf62ae1975b64ffeaf00e4ae9610f4a026957bdc8e6e6aa33b0
 * Entry: 0x6997a0; label: FUN_006997a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

