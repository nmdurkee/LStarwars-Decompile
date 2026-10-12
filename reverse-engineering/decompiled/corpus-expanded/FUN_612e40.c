/* Ghidra pseudocode, not original source.
 * ev_ba1f842bfa0104f1b5ed7b121d230225c91ad84bbbac79703c0a3e54823fb4da
 * Entry: 0x612e40; label: FUN_00612e40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00612e40(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  piVar3 = (int *)(in_ECX + 0xd858);
  iVar4 = 2;
  do {
    if (((piVar3[-8] != 0) && (iVar1 = piVar3[-5], iVar1 != 3)) &&
       ((iVar2 != 0 || ((iVar1 < 1 || (iVar2 = 1, 2 < iVar1)))))) {
      iVar2 = 2;
    }
    if (((piVar3[-3] != 0) && (iVar1 = *piVar3, iVar1 != 3)) &&
       ((iVar2 != 0 || ((iVar1 < 1 || (iVar2 = 1, 2 < iVar1)))))) {
      iVar2 = 2;
    }
    if (((piVar3[2] != 0) && (iVar1 = piVar3[5], iVar1 != 3)) &&
       ((iVar2 != 0 || ((iVar1 < 1 || (iVar2 = 1, 2 < iVar1)))))) {
      iVar2 = 2;
    }
    if (((piVar3[7] != 0) && (iVar1 = piVar3[10], iVar1 != 3)) &&
       ((iVar2 != 0 || ((iVar1 < 1 || (iVar2 = 1, 2 < iVar1)))))) {
      iVar2 = 2;
    }
    piVar3 = piVar3 + 0x14;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}

