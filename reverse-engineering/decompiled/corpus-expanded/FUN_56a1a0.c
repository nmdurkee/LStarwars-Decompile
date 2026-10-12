/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x56a1a0; label: FUN_0056a1a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0056a1a0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x50c8);
  if (iVar1 != 0) {
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x50c0)) {
      do {
        if (*(short *)(iVar1 + 0x102) == param_2) {
          return iVar1;
        }
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x114;
      } while (iVar2 < *(int *)(param_1 + 0x50c0));
    }
  }
  return 0;
}

