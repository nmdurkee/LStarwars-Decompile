/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575ad0; label: FUN_00575ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_00575ad0(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    return *(char *)(*param_1 + 0xf7) == '\0';
  }
  return false;
}

