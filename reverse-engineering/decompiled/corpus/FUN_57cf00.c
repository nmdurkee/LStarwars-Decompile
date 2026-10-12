/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57cf00; label: FUN_0057cf00
 */

void FUN_0057cf00(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    iVar3 = 0;
    if (0 < param_1[1]) {
      do {
        iVar1 = *(int *)(*(int *)(*param_1 + iVar3 * 4) + 4);
        if (iVar1 != 0) {
          FUN_00507c00(iVar1);
          *(undefined4 *)(*(int *)(*param_1 + iVar3 * 4) + 4) = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[1]);
    }
    iVar3 = 0;
    if (0 < param_1[1]) {
      do {
        piVar2 = *(int **)(*param_1 + iVar3 * 4);
        if (*piVar2 != 0) {
          FUN_00505b20(*piVar2);
          **(undefined4 **)(*param_1 + iVar3 * 4) = 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < param_1[1]);
    }
  }
  return;
}

