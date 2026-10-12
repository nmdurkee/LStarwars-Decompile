/* Ghidra pseudocode, not original source.
 * ev_a37d45c54d4922ce68f22ac83ec0c43bcdcd42a61686a123418b5247712e53b1
 * Entry: 0x59a6b0; label: FUN_0059a6b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0059a6b0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (iVar2 = *(int *)(param_1 + 4), iVar2 != 0)) && (param_2 != 0)) {
    if (iVar2 == param_2) {
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar2 + 0x38);
      *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 8);
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
      *(int *)(param_1 + 8) = param_2;
      return;
    }
    if (*(int *)(iVar2 + 0x38) != 0) {
      while (iVar1 = *(int *)(iVar2 + 0x38), iVar1 != param_2) {
        iVar2 = iVar1;
        if (*(int *)(iVar1 + 0x38) == 0) {
          *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
          return;
        }
      }
      *(undefined4 *)(iVar2 + 0x38) = *(undefined4 *)(param_2 + 0x38);
      *(undefined4 *)(param_2 + 0x38) = *(undefined4 *)(param_1 + 8);
      *(int *)(param_1 + 8) = param_2;
    }
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  }
  return;
}

