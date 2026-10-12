/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51ac70; label: FUN_0051ac70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0051ac70(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 != 0) && (iVar3 = 0, 0 < *(int *)(param_1 + 0x2c))) {
    iVar2 = 0;
    do {
      iVar1 = FUN_004f8b10(*(int *)(param_1 + 0x30) + iVar2,param_2);
      if (iVar1 == 0) {
        return *(int *)(param_1 + 0x30) + iVar3 * 0x1c;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x1c;
    } while (iVar3 < *(int *)(param_1 + 0x2c));
  }
  return 0;
}

