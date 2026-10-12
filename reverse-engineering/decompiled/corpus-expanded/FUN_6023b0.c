/* Ghidra pseudocode, not original source.
 * ev_fc1ff40c7a3094b1e589789cc6fd4e7c7ceccf6febfdd6935cf97a0e254c7b0e
 * Entry: 0x6023b0; label: FUN_006023b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006023b0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int iVar8;
  int local_4;
  
  iVar3 = param_1;
  iVar8 = *(int *)(param_1 + 0x110);
  if ((iVar8 != 0) && (local_4 = 0, 0 < *(int *)(iVar8 + 4))) {
    param_1 = 0;
    do {
      pcVar4 = (char *)(*(int *)(iVar8 + 8) + param_1);
      cVar1 = *pcVar4;
      if (cVar1 == -0x50) {
        piVar2 = *(int **)(pcVar4 + 4);
        if (*piVar2 == 2) {
          piVar7 = piVar2 + 2;
          iVar8 = 3;
          do {
            iVar5 = FUN_005eed30(iVar3,*piVar7);
            *piVar7 = iVar5;
            piVar7 = piVar7 + 1;
            iVar8 = iVar8 + -1;
          } while (iVar8 != 0);
        }
        iVar8 = FUN_005eed30(iVar3,piVar2[1]);
        piVar2[1] = iVar8;
      }
      else if (((cVar1 == -0x52) || (cVar1 == -0x51)) && (iVar8 = *(int *)(pcVar4 + 4), iVar8 != 0))
      {
        iVar5 = 0;
        do {
          uVar6 = FUN_005eed30(iVar3,*(undefined4 *)(iVar8 + iVar5 * 4));
          *(undefined4 *)(iVar8 + iVar5 * 4) = uVar6;
          iVar5 = iVar5 + 1;
        } while (iVar5 < 3);
      }
      iVar8 = *(int *)(iVar3 + 0x110);
      param_1 = param_1 + 0x10;
      local_4 = local_4 + 1;
    } while (local_4 < *(int *)(iVar8 + 4));
  }
  return;
}

