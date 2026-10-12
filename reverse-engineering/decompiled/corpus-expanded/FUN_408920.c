/* Ghidra pseudocode, not original source.
 * ev_c99ba83a21253fbea00a1b2af974464e548d813850fcca855330552d9e62c3cd
 * Entry: 0x408920; label: FUN_00408920
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00408920(int *param_1)

{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if ((iVar1 != 0) && (*(int **)(iVar1 + 0x1040) == param_1)) {
      *(undefined4 *)(iVar1 + 0x1040) = 0;
    }
    _memset(param_1,0,0x1ec);
  }
  return;
}

