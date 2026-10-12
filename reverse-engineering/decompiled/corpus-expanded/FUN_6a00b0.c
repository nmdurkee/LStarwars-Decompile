/* Ghidra pseudocode, not original source.
 * ev_3229c3221a199ea2fa72efff5d47b38f22dfc944c4167cffdb72b8afc53424db
 * Entry: 0x6a00b0; label: FUN_006a00b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006a00b0(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = 0;
    if (0 < param_1[2]) {
      do {
        if (*(int *)(*param_1 + iVar1 * 4) != 0) {
          _free(*(void **)(*param_1 + iVar1 * 4));
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < param_1[2]);
    }
    if ((void *)*param_1 != (void *)0x0) {
      _free((void *)*param_1);
    }
    if ((void *)param_1[1] != (void *)0x0) {
      _free((void *)param_1[1]);
    }
    if ((void *)param_1[3] != (void *)0x0) {
      _free((void *)param_1[3]);
    }
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
  }
  return;
}

