/* Ghidra analysis pseudocode, not original source.
 * ev_1c7a82f294435201fd9406ba2f36685e25c9dd11fb4cb3b46f5b103b3befd94c
 * Entry: 0x603980; label: FUN_00603980
 */

void FUN_00603980(int param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 4)) {
    iVar2 = 0;
    do {
      pcVar1 = (char *)(*(int *)(param_1 + 8) + iVar2);
      if (*pcVar1 == -0x7e) {
        *pcVar1 = -0x7e;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10;
    } while (iVar3 < *(int *)(param_1 + 4));
  }
  return;
}

