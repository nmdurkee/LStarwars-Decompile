/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x6174d0; label: FUN_006174d0
 */

int FUN_006174d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = in_ECX + 4;
  while( true ) {
    if (iVar2 == in_ECX + 0x1604) {
      return 0;
    }
    if ((((*(int *)(iVar2 + 0xac) != 0) && (iVar1 = FUN_00617180(param_2), iVar1 == 0)) &&
        (iVar1 = FUN_004f8b10(iVar2 + 0xc,param_1), iVar1 == 0)) &&
       ((param_3 == 0 || (*(int *)(iVar2 + 4) == param_3)))) break;
    iVar2 = iVar2 + 0xb0;
  }
  return iVar2;
}

