/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x6175e0; label: FUN_006175e0
 */

void FUN_006175e0(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 != 0) {
    if (*(uint *)(iVar2 + 0x4b0) < 2) {
      *(undefined4 *)(iVar2 + 0x4b0) = 0;
    }
    else {
      *(uint *)(iVar2 + 0x4b0) = *(uint *)(iVar2 + 0x4b0) - 1;
    }
  }
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_1 + 0xc);
  if (*(int *)(in_ECX + 4) != 0) {
    piVar1 = (int *)(*(int *)(in_ECX + 4) + 0x4b0);
    *piVar1 = *piVar1 + 1;
  }
  return;
}

