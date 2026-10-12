/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x617660; label: FUN_00617660
 */

void FUN_00617660(void)

{
  undefined4 uVar1;
  int in_ECX;
  int local_c;
  
  if ((((*(int *)(in_ECX + 4) == 1) && (*(int *)(in_ECX + 0xa0) != 0)) &&
      (*(int *)(*(int *)(in_ECX + 0xa0) + 0x4b0) == 1)) && (*(int *)(in_ECX + 8) == 1)) {
    uVar1 = FUN_0053d5d0(0xc);
    FUN_006175e0(uVar1);
    if (local_c != 0) {
      if (1 < *(uint *)(local_c + 0x4b0)) {
        *(uint *)(local_c + 0x4b0) = *(uint *)(local_c + 0x4b0) - 1;
        return;
      }
      *(undefined4 *)(local_c + 0x4b0) = 0;
    }
  }
  return;
}

