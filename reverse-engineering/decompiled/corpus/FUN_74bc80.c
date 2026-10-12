/* Ghidra analysis pseudocode, not original source.
 * ev_d43409c1beaf04de5181c7e79b8ae898b4513b764b0aa0772119c8ac5b4cb60b
 * Entry: 0x74bc80; label: FUN_0074bc80
 */

void FUN_0074bc80(byte param_1)

{
  undefined4 *in_ECX;
  
  if ((void *)*in_ECX != (void *)0x0) {
    _free((void *)*in_ECX);
    *in_ECX = 0;
  }
  FUN_00748490();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

