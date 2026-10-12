/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b59f0; label: FUN_006b59f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_006b59f0(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  int in_EDX;
  
  iVar2 = *(int *)(in_EAX + in_ECX * 4);
  if (iVar2 < 0) {
    return *(int *)(in_EDX + in_ECX * 4);
  }
  iVar1 = *(int *)(in_EDX + in_ECX * 4);
  if (-1 < iVar1) {
    iVar2 = iVar2 + iVar1 >> 1;
  }
  return iVar2;
}

