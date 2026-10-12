/* Ghidra pseudocode, not original source.
 * ev_659eea1dc00a859f9d32b97d98369d0a367714cfb07a93b4448bfffc51247c8f
 * Entry: 0x7030f3; label: FUN_007030f3
 * Boundary hypotheses: reports/native-supplemental-entry-inspection.json.
 */

undefined1 * FUN_007030f3(undefined1 *param_1,int param_2)

{
  int in_ECX;
  
  if ((param_1 == (undefined1 *)0x0) || (param_2 == 0)) {
    param_1 = (undefined1 *)0x0;
  }
  else {
    *param_1 = *(undefined1 *)(in_ECX + 8);
  }
  return param_1;
}

