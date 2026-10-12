/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694cc0; label: FUN_00694cc0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694cc0(float param_1)

{
  float fVar1;
  int in_ECX;
  
  fVar1 = param_1;
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    if (1.0 < param_1) {
      param_1 = 1.0;
    }
    if (param_1 < 0.0) {
      *(undefined4 *)(in_ECX + 0x198) = 0;
      return;
    }
    if (1.0 < fVar1) {
      *(undefined4 *)(in_ECX + 0x198) = 0x3f800000;
      return;
    }
    *(float *)(in_ECX + 0x198) = fVar1;
  }
  return;
}

