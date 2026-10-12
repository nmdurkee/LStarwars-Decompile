/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x6179c0; label: FUN_006179c0
 */

undefined4 FUN_006179c0(void)

{
  float10 fVar1;
  undefined4 local_8 [2];
  
  FUN_004f3bd0(local_8);
  fVar1 = (float10)FUN_004f3d10(local_8);
  local_8[0] = (undefined4)(longlong)ROUND(fVar1);
  return local_8[0];
}

