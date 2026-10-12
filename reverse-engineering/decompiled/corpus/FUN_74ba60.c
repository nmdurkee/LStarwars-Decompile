/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74ba60; label: FUN_0074ba60
 */

void FUN_0074ba60(void)

{
  undefined4 *in_ECX;
  
  if ((void *)*in_ECX != (void *)0x0) {
    _free((void *)*in_ECX);
    *in_ECX = 0;
  }
  FUN_00748490();
  return;
}

