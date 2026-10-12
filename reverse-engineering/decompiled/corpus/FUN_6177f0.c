/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x6177f0; label: FUN_006177f0
 */

void FUN_006177f0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  for (iVar2 = in_ECX + 4; iVar2 != in_ECX + 0x1604; iVar2 = iVar2 + 0xb0) {
    if (*(int *)(iVar2 + 0xac) != 0) {
      FUN_0060e450(iVar2,0xa0200001);
      if ((*(int *)(iVar2 + 0xac) != 0) && (iVar1 = *(int *)(iVar2 + 0xa0), iVar1 != 0)) {
        if (*(uint *)(iVar1 + 0x4b0) < 2) {
          *(undefined4 *)(iVar1 + 0x4b0) = 0;
        }
        else {
          *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
        }
      }
      *(undefined4 *)(iVar2 + 0xac) = 0;
    }
  }
  return;
}

