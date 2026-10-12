/* Ghidra pseudocode, not original source.
 * ev_3968740630932d2cb6945455b13b10dc603e92ef7b36def715db8f60cd47147a
 * Entry: 0x6dd2b0; label: FUN_006dd2b0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_006dd2b0(HWND param_1,int param_2)

{
  ShowWindow(param_1,param_2);
  UpdateWindow(param_1);
  DAT_00924864 = param_1;
  return 1;
}

