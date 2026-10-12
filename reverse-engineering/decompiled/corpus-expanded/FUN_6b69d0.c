/* Ghidra pseudocode, not original source.
 * ev_8eef0e367f1a27c7ef4dce890dd1e02a98f2c666b50c9e5dab0b6aeb2e260fd2
 * Entry: 0x6b69d0; label: FUN_006b69d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006b69d0(undefined4 *param_1)

{
  int *piVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      if (*piVar1 != 0) {
        _free((void *)*piVar1);
      }
      if (*(int *)(param_1[2] + 4) != 0) {
        _free(*(void **)(param_1[2] + 4));
      }
      _free((void *)param_1[2]);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = 0;
    param_1[6] = 0;
    param_1[7] = 0;
    _free(param_1);
  }
  return;
}

