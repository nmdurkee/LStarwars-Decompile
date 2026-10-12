/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e0f50; label: FUN_005e0f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e0f50(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x10)) {
    do {
      if (*(float *)(*(int *)(param_1 + 0x28) + iVar1 * 4) != 0.0) {
        *(undefined4 *)(*(int *)(param_1 + 0x28) + iVar1 * 4) = 0x7f7fffff;
      }
      *(undefined4 *)(*(int *)(param_1 + 0x2c) + iVar1 * 4) = 0x7f7fffff;
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x10));
  }
  return;
}

