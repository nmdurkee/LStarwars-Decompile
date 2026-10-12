/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x617180; label: FUN_00617180
 */

undefined4 FUN_00617180(byte *param_1)

{
  undefined4 uVar1;
  byte *in_ECX;
  uint uVar2;
  int iVar3;
  
  uVar2 = 4;
  do {
    if (*(int *)param_1 != *(int *)in_ECX) goto LAB_006171a8;
    uVar2 = uVar2 - 4;
    in_ECX = in_ECX + 4;
    param_1 = param_1 + 4;
  } while (3 < uVar2);
  if (uVar2 == 0) {
LAB_00617208:
    uVar1 = 0;
  }
  else {
LAB_006171a8:
    iVar3 = (uint)*param_1 - (uint)*in_ECX;
    if (iVar3 == 0) {
      if (uVar2 == 1) goto LAB_00617208;
      iVar3 = (uint)param_1[1] - (uint)in_ECX[1];
      if (iVar3 == 0) {
        if (uVar2 == 2) goto LAB_00617208;
        iVar3 = (uint)param_1[2] - (uint)in_ECX[2];
        if (iVar3 == 0) {
          if ((uVar2 == 3) || (iVar3 = (uint)param_1[3] - (uint)in_ECX[3], iVar3 == 0))
          goto LAB_00617208;
        }
      }
    }
    uVar1 = 1;
    if (iVar3 < 1) {
      return 0xffffffff;
    }
  }
  return uVar1;
}

