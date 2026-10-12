/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x497720; label: FUN_00497720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00497720(int *param_1,int param_2)

{
  param_1[1] = *param_1 + param_2 * 0x18;
  *(undefined1 *)((int)param_1 + 0x1d) = 1;
  FUN_00548fb0(param_1 + 2,0);
  FUN_0056e2e0(0);
  return;
}

