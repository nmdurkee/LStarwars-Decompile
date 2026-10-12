/* Ghidra analysis pseudocode, not original source.
 * ev_7c321bc51ff35622de6c5d479df857df6f5bf01a82339419049d6b39c5416ee3
 * Entry: 0x74d790; label: FUN_0074d790
 */

void FUN_0074d790(void)

{
  int in_ECX;
  
  FUN_0074d690();
  FUN_00748490();
  if (*(void **)(in_ECX + 0x104) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x104));
  }
  *(undefined4 *)(in_ECX + 0x104) = 0;
  *(undefined4 *)(in_ECX + 0x108) = 0;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  return;
}

