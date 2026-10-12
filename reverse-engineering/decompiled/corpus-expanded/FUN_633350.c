/* Ghidra pseudocode, not original source.
 * ev_11aaf33bc566dbb5337d0358c8c7e7b90799e20019d0aefa05560726d7209bd1
 * Entry: 0x633350; label: FUN_00633350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00633350(void *param_1)

{
  if (param_1 != (void *)0x0) {
    if (*(int *)((int)param_1 + 0x20) != 0) {
      if (*(int *)((int)param_1 + 0x4c) != 0) {
        (**(code **)(**(int **)((int)param_1 + 0x4c) + 8))(*(int **)((int)param_1 + 0x4c));
      }
      _free(param_1);
      return;
    }
    FUN_00632a10(param_1);
  }
  return;
}

