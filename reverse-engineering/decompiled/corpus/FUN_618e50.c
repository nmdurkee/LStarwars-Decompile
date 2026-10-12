/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x618e50; label: FUN_00618e50
 */

void FUN_00618e50(int *param_1,int *param_2)

{
  if (*param_1 == 0) {
    param_1[1] = (int)param_2;
  }
  else {
    *(int **)(*param_1 + 4) = param_2;
  }
  param_2[1] = 0;
  *param_2 = *param_1;
  *param_1 = (int)param_2;
  param_1[3] = (int)param_2;
  DAT_02900c84 = param_2;
  param_1[4] = 0;
  return;
}

