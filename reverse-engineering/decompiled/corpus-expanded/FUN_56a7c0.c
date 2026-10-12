/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x56a7c0; label: FUN_0056a7c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0056a7c0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x50c0)) {
    piVar5 = (int *)(*(int *)(param_1 + 0x50c8) + 0xa4);
    do {
      if (((*(uint *)(*piVar5 + 0x7c) & 0x2000) != 0) && ((piVar5[-3] & 0x800000U) == 0)) {
        FUN_005cfc00(*piVar5 + 0x30,0);
      }
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 0x45;
    } while (iVar3 < *(int *)(param_1 + 0x50c0));
  }
  iVar3 = 0;
  if (0 < *(int *)(param_1 + 0x50bc)) {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(param_1 + 0x50c4) + iVar4 + 0x3c;
      iVar2 = FUN_005cfac0(iVar1);
      if (iVar2 != 0) {
        FUN_005cfc00(iVar1,0);
      }
      iVar3 = iVar3 + 1;
      iVar4 = iVar4 + 0x100;
    } while (iVar3 < *(int *)(param_1 + 0x50bc));
  }
  return;
}

