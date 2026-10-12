/* Ghidra analysis pseudocode, not original source.
 * ev_95c8e418da29cc632cb1d5f63d18656279f3531c253a180fe75fe8327a27ff44
 * Entry: 0x632a10; label: FUN_00632a10
 */

void FUN_00632a10(void *param_1)

{
  int *piVar1;
  uint uVar2;
  
  if (*(int *)((int)param_1 + 0x48) != 0) {
    uVar2 = 0;
    if (*(int *)((int)param_1 + 0x28) != 0) {
      do {
        if (*(int *)(*(int *)((int)param_1 + 0x48) + uVar2 * 4) != 0) {
          piVar1 = *(int **)(*(int *)((int)param_1 + 0x48) + uVar2 * 4);
          (**(code **)(*piVar1 + 8))(piVar1);
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)((int)param_1 + 0x28));
    }
    *(undefined4 *)((int)param_1 + 0x48) = 0;
    _free(param_1);
  }
  return;
}

