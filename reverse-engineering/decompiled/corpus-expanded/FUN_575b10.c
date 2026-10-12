/* Ghidra pseudocode, not original source.
 * ev_b8f4d44f892ded82cd7ffb9ce06d4ee71453c0b8ed59e2b020606927ce90ab67
 * Entry: 0x575b10; label: FUN_00575b10
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00575b10(int *param_1,int param_2)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    *(bool *)(*param_1 + 0xf7) = param_2 == 0;
  }
  return;
}

