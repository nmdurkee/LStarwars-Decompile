/* Ghidra analysis pseudocode, not original source.
 * ev_51d776bbf7e198208a4486308eec4a97f7acd5ccc3951e1c43c2ae0a52a9ca8f
 * Entry: 0x6c2610; label: FUN_006c2610
 */

void FUN_006c2610(int param_1)

{
  int in_ECX;
  int iVar1;
  int extraout_EDX;
  float *pfVar2;
  int iVar3;
  float10 fVar4;
  
  iVar3 = DAT_02973bac;
  if (9 < DAT_02973bac) {
    iVar3 = 10;
  }
  iVar1 = 0;
  if (0 < iVar3) {
    pfVar2 = (float *)(param_1 + 0x180);
    do {
      if (((iVar1 + 0x1aU < 0x28) && (*(char *)(iVar1 + 0x92 + param_1) != '\0')) &&
         (*pfVar2 != 0.0)) {
        fVar4 = (float10)FUN_006b97c0(0x16);
        iVar1 = extraout_EDX;
        if ((float10)0 == fVar4) {
          *(uint *)(in_ECX + 0x6c) = *(uint *)(in_ECX + 0x6c) ^ 1 << ((byte)extraout_EDX & 0x1f);
        }
        else {
          *(int *)(in_ECX + 0x6c) = 1 << ((byte)extraout_EDX & 0x1f);
        }
      }
      iVar1 = iVar1 + 1;
      pfVar2 = pfVar2 + 1;
    } while (iVar1 < iVar3);
  }
  if ((*(char *)(param_1 + 0x9c) != '\0') && (*(float *)(param_1 + 0x1a8) != 0.0)) {
    if ((*(char *)(param_1 + 0x66) != '\0') && (*(float *)(param_1 + 0x170) != 0.0)) {
      *(undefined4 *)(in_ECX + 0x6c) = 0xffffffff;
      return;
    }
    *(uint *)(in_ECX + 0x6c) = ~*(uint *)(in_ECX + 0x6c);
    return;
  }
  return;
}

