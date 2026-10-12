/* Ghidra analysis pseudocode, not original source.
 * ev_8a1c0c5e10d6654d222815d2fcbabbb2010894af729ab08cddb68e86cf286c6b
 * Entry: 0x616a80; label: FUN_00616a80
 */

int FUN_00616a80(int param_1,undefined4 param_2,int param_3)

{
  ushort *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  int *extraout_ECX;
  int *piVar4;
  bool bVar5;
  undefined8 uVar6;
  
  bVar5 = false;
  if (param_3 == 0) {
    param_3 = FUN_00612a50();
    bVar5 = param_3 == 0;
  }
  if (!bVar5 && -1 < param_3) {
    iVar2 = 0;
    piVar4 = (int *)(in_ECX + 0x3c);
    do {
      uVar6 = CONCAT44(param_1,iVar2);
      if (*piVar4 == param_1) {
        if (*(char *)(in_ECX + 0xd96c) == '\0') {
          return 0;
        }
        uVar6 = FUN_00611890();
        piVar4 = extraout_ECX;
      }
      param_1 = (int)((ulonglong)uVar6 >> 0x20);
      iVar2 = (int)uVar6 + 1;
      piVar4 = piVar4 + 6;
    } while (iVar2 < 0x800);
    puVar1 = (ushort *)(in_ECX + (param_3 * 3 + 6) * 8);
    uVar3 = *(undefined4 *)(DAT_028572e0 + 0x84);
    *puVar1 = *puVar1 | 1;
    *(undefined4 *)(puVar1 + 8) = param_2;
    puVar1[1] = (ushort)param_3;
    *(int *)(puVar1 + 6) = param_1;
    *(undefined4 *)(puVar1 + 4) = uVar3;
    iVar2 = FUN_006be780(param_2);
    if (0 < *(int *)(&DAT_02867f1c + iVar2 * 4)) {
      uVar3 = FUN_00633440(*(int *)(&DAT_02867f1c + iVar2 * 4),1);
      *(undefined4 *)(puVar1 + 10) = uVar3;
    }
    FUN_00612ac0(puVar1);
    if (*(int *)(in_ECX + 0xc) != 0) {
      FUN_006160b0(puVar1,in_ECX + 0xd8d8);
      FUN_00615ff0();
    }
  }
  return param_3;
}

