/* Ghidra analysis pseudocode, not original source.
 * ev_9251851307bb379bfc9bcabd13d9f753a758e856e200aa29981eaf91127b618c
 * Entry: 0x573b80; label: FUN_00573b80
 */

void FUN_00573b80(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 300);
  if (((iVar3 != 0) && (*(int *)(iVar3 + 0x80) != 0)) &&
     (iVar2 = 0, *(char *)(iVar3 + 0x7f) != '\0')) {
    iVar3 = 0;
    do {
      pbVar1 = (byte *)(*(int *)(*(int *)(param_1 + 300) + 0x80) + 0x1e7 + iVar3);
      *pbVar1 = *pbVar1 & 0xfd;
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x1e8;
    } while (iVar2 < (int)(uint)*(byte *)(*(int *)(param_1 + 300) + 0x7f));
  }
  return;
}

