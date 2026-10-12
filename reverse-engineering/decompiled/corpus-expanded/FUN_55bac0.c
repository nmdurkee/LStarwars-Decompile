/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55bac0; label: FUN_0055bac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0055bac0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (*(char *)(param_1 + 0x11f) != '\0') {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(param_2,*(int *)(param_1 + 4) + iVar2);
      if (iVar1 == 0) {
        return (int)*(short *)(*(int *)(param_1 + 4) + 0x18 + iVar3 * 0x1c);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar3 < (int)(uint)*(byte *)(param_1 + 0x11f));
  }
  return -1;
}

