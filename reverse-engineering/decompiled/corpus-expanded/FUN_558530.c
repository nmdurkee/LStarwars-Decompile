/* Ghidra pseudocode, not original source.
 * ev_f8ed381e2b466dd5bc773ab3f84ab60966b69e10a49b3e28fcf3f54e00ea1563
 * Entry: 0x558530; label: FUN_00558530
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00558530(int param_1,undefined4 param_2,undefined4 param_3)

{
  if (((*(char *)(param_1 + 0x90) != '\0') || (*(int *)(*(int *)(param_1 + 0x34) + 0xc) != 2)) ||
     ((*(uint *)(param_1 + 0x68) & 0x100) != 0)) {
    *(uint *)(param_1 + 0x94) = *(uint *)(param_1 + 0x94) | 8;
    *(undefined4 *)(param_1 + 0x48) = param_3;
    *(undefined4 *)(param_1 + 0x38) = param_2;
  }
  return;
}

