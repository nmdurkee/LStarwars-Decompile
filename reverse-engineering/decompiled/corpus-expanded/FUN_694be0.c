/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694be0; label: FUN_00694be0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00694be0(int param_1)

{
  int *in_ECX;
  
  if ((((in_ECX != (int *)0x0) && (DAT_02962b8c != 0)) && (0x12345677 < param_1)) &&
     (param_1 + -0x12345678 < in_ECX[1])) {
    in_ECX[0x76] = *in_ECX + (param_1 + -0x12345678) * 0x24;
    return 1;
  }
  return 0;
}

