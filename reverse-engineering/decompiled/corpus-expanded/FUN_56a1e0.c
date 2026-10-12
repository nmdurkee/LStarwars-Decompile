/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x56a1e0; label: FUN_0056a1e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056a1e0(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x50c8);
  if ((iVar3 != 0) && (iVar2 = 0, 0 < *(int *)(param_1 + 0x50c0))) {
    do {
      iVar1 = FUN_004f8b10(iVar3 + 0xf2,param_2);
      if (iVar1 == 0) {
        return iVar3;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x114;
    } while (iVar2 < *(int *)(param_1 + 0x50c0));
  }
  return 0;
}

