/* Ghidra analysis pseudocode, not original source.
 * ev_f3574efba8633d4b71eb16d1e05784af9695c720a67aab99b2425d0d63eee0b9
 * Entry: 0x497720; label: FUN_00497720
 */

void FUN_00497720(int *param_1,int param_2)

{
  param_1[1] = *param_1 + param_2 * 0x18;
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  FUN_00548fb0(param_1 + 2,0);
  FUN_0056e2e0(0);
  return;
}

