/* Ghidra pseudocode, not original source.
 * ev_fe5af94714569ca149d7ee11beb07ec697c406bef5bd6833183fcd21241d309c
 * Entry: 0x51acd0; label: FUN_0051acd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0051acd0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 != 0) && (iVar3 = 0, 0 < *(int *)(param_1 + 0x34))) {
    iVar2 = 0;
    do {
      iVar4 = *(int *)(param_1 + 0x38) + iVar2;
      iVar1 = FUN_004f8b10(param_2,iVar4);
      if (iVar1 == 0) {
        return iVar4;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x40;
    } while (iVar3 < *(int *)(param_1 + 0x34));
  }
  return 0;
}

