/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694d50; label: FUN_00694d50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694d50(undefined4 param_1,float param_2)

{
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    if (param_2 != 0.0) {
      *(float *)(in_ECX + 0x1a4) = 1.0 / param_2;
      *(undefined4 *)(in_ECX + 0x1a0) = param_1;
      return;
    }
    *(undefined4 *)(in_ECX + 0x1a0) = param_1;
    *(undefined4 *)(in_ECX + 0x19c) = param_1;
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
  }
  return;
}

