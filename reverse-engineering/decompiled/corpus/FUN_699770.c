/* Ghidra analysis pseudocode, not original source.
 * ev_f1a36c6b3ad286842b1ed86bd3c2163f44c7dc63d65997010e74903b0be7db2b
 * Entry: 0x699770; label: FUN_00699770
 */

undefined4 FUN_00699770(void)

{
  int in_ECX;
  
  if ((in_ECX != 0) &&
     ((*(int *)(in_ECX + 0x1b8) != 0 || ((*(int *)(in_ECX + 8) != 0 && (*(int *)(in_ECX + 8) != 3)))
      ))) {
    return 0;
  }
  return 1;
}

