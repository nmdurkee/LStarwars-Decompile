/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x616510; label: FUN_00616510
 */

void FUN_00616510(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  
  piVar2 = param_1;
  if (param_1[1] != 0) {
    FUN_004ef660(&param_1,param_1[2] + param_1[1],2);
    if (*piVar2 != 0) {
      FUN_00621180(&param_1);
    }
    piVar2 = piVar2 + 2;
    *piVar2 = *piVar2 + 2;
  }
  *(undefined4 *)(in_ECX + 0x38 + (short)param_1 * 0x18) = *(undefined4 *)(DAT_028572e0 + 0x84);
  FUN_00612ac0(in_ECX + ((short)param_1 + 2) * 0x18);
  FUN_006157f0(param_1);
  FUN_0060e4c0(in_ECX + ((short)param_1 * 3 + 6) * 8,
               *(undefined4 *)(in_ECX + 0x38 + (short)param_1 * 0x18));
  iVar1 = 0;
  piVar2 = (int *)(in_ECX + 0xd03c);
  do {
    if (*piVar2 == in_ECX + ((short)param_1 + 2) * 0x18) {
      *(undefined4 *)(in_ECX + 0xd03c + iVar1 * 0xc) = 0;
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 3;
  } while (iVar1 < 0x20);
  return;
}

