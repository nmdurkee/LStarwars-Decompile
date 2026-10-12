/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x618e10; label: FUN_00618e10
 */

void FUN_00618e10(undefined4 *param_1,undefined4 *param_2)

{
  if ((undefined4 *)param_1[1] == (undefined4 *)0x0) {
    *param_1 = param_2;
  }
  else {
    *(undefined4 *)param_1[1] = param_2;
  }
  param_2[1] = param_1[1];
  *param_2 = 0;
  param_1[1] = param_2;
  param_1[3] = *param_1;
  DAT_02900c84 = param_2;
  param_1[4] = 0;
  return;
}

