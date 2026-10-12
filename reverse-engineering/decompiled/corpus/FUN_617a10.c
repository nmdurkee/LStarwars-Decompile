/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x617a10; label: FUN_00617a10
 */

void FUN_00617a10(void)

{
  float10 fVar1;
  undefined4 local_8;
  
  FUN_004f3bd0(&DAT_02900a48);
  fVar1 = (float10)FUN_004f3d10(&DAT_02900a48);
  local_8 = (undefined4)(longlong)ROUND(fVar1);
  DAT_02900a44 = local_8;
  return;
}

