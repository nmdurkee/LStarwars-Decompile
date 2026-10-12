/* Ghidra analysis pseudocode, not original source.
 * ev_04eba8a6041128e42a5942cb543eca22153343fab03a80410cc8a046c9872535
 * Entry: 0x51fe60; label: FUN_0051fe60
 */

void FUN_0051fe60(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  
  if (((param_2 != 0) && (DAT_009238dc != (code *)0x0)) &&
     (iVar4 = 0, '\0' < *(char *)(param_2 + 0x10))) {
    do {
      cVar1 = *(char *)(iVar4 + *(int *)(param_2 + 0x18));
      if ((cVar1 != -1) && (cVar1 != -0x80)) {
        cVar3 = -1;
        iVar2 = (*DAT_009238dc)(cVar1);
        if ((iVar2 != 0) &&
           ((*(int *)(iVar2 + 4) != 0 && (iVar2 = *(int *)(*(int *)(iVar2 + 4) + 0xa4), iVar2 != 0))
           )) {
          cVar3 = (char)((iVar2 - *(int *)(param_1 + 0x28)) / 0x3c);
        }
        if (cVar3 != *(char *)(iVar4 + *(int *)(param_2 + 0x14))) {
          *(undefined1 *)(iVar4 + *(int *)(param_2 + 0x18)) = 0xff;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(char *)(param_2 + 0x10));
  }
  return;
}

