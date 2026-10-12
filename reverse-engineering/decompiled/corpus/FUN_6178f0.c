/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x6178f0; label: FUN_006178f0
 */

void FUN_006178f0(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  *in_ECX = &PTR_FUN_0076aca0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1 = puVar1 + 0x2c;
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
  } while (-1 < iVar2);
  in_ECX[0x581] = 0;
  return;
}

