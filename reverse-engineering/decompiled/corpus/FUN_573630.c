/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573630; label: FUN_00573630
 */

void FUN_00573630(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != -1) && (param_1 = param_1 * 0x9c, *(int *)(param_1 + 0x80 + DAT_00951354) != 0))
     && (iVar1 = 0, *(char *)(param_1 + 0x7f + DAT_00951354) != '\0')) {
    iVar2 = 0;
    do {
      *(undefined2 *)(*(int *)(param_1 + 0x80 + DAT_00951354) + 0x1e2 + iVar2) = 0;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0x1e8;
    } while (iVar1 < (int)(uint)*(byte *)(param_1 + 0x7f + DAT_00951354));
  }
  return;
}

