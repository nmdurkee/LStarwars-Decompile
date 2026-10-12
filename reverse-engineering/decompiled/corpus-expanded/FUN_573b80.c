/* Ghidra pseudocode, not original source.
 * ev_f349b1a9efc39563d2f2ebe5dc458b8d9d47a8328d1b609022bb24691faec82f
 * Entry: 0x573b80; label: FUN_00573b80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

