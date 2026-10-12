/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x6331a0; label: FUN_006331a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006331a0(void *param_1)

{
  if (*(int *)((int)param_1 + 0x4c) != 0) {
    (**(code **)(**(int **)((int)param_1 + 0x4c) + 8))(*(int **)((int)param_1 + 0x4c));
  }
  _free(param_1);
  return;
}

