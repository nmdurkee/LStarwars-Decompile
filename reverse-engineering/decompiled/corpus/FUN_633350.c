/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x633350; label: FUN_00633350
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

