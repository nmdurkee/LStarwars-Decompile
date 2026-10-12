/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c4470; label: FUN_006c4470
 */

void FUN_006c4470(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = *(int **)(in_ECX + 0x93c); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
    (**(code **)(*piVar1 + 0x1c))();
  }
  *(undefined4 *)(in_ECX + 0x2a8) = 0;
  _memset((void *)(in_ECX + 0x2ac),0,0x690);
  return;
}

