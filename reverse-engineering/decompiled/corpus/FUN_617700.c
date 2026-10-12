/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x617700; label: FUN_00617700
 */

void FUN_00617700(byte param_1)

{
  int iVar1;
  void *in_ECX;
  
  iVar1 = *(int *)((int)in_ECX + 0xa0);
  if (iVar1 != 0) {
    if (*(uint *)(iVar1 + 0x4b0) < 2) {
      *(undefined4 *)(iVar1 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar1 + 0x4b0) = *(uint *)(iVar1 + 0x4b0) - 1;
    }
  }
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

