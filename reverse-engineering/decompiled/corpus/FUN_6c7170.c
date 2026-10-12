/* Ghidra analysis pseudocode, not original source.
 * ev_b11735056f517841e68fc69c6a59e9f65c2ea93b1b22364b6a9fa70acd21d770
 * Entry: 0x6c7170; label: FUN_006c7170
 */

int * FUN_006c7170(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = FUN_00633440(0xd0,1);
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_006c6d60();
    if (piVar2 != (int *)0x0) {
      piVar2[0xb] = 0;
      piVar2[0xc] = *(int *)(in_ECX + 0x9c);
      if (*(int *)(in_ECX + 0x9c) != 0) {
        *(int **)(*(int *)(in_ECX + 0x9c) + 0x2c) = piVar2;
      }
      *(int **)(in_ECX + 0x9c) = piVar2;
      if (*(int *)(in_ECX + 0x98) == 0) {
        *(int **)(in_ECX + 0x98) = piVar2;
      }
      *(int *)(in_ECX + 0xa0) = *(int *)(in_ECX + 0xa0) + 1;
      (**(code **)(*piVar2 + 0x10))("object");
    }
    return piVar2;
  }
  return (int *)0x0;
}

