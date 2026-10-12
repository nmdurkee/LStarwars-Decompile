/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x617970; label: FUN_00617970
 */

void FUN_00617970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_0076aca0;
  FUN_00617790();
  *in_ECX = &PTR_LAB_0076105c;
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

