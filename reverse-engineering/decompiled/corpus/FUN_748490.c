/* Ghidra analysis pseudocode, not original source.
 * ev_7afb5199773593ea980580d1c3e319946e9fb0192a7e36f1658c723ed800643d
 * Entry: 0x748490; label: FUN_00748490
 */

void FUN_00748490(void)

{
  undefined4 *in_ECX;
  
  if (((void *)*in_ECX != (void *)0x0) && (*(char *)(in_ECX + 3) != '\0')) {
    _free((void *)*in_ECX);
    *in_ECX = 0;
  }
  return;
}

