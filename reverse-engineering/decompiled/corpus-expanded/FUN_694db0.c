/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x694db0; label: FUN_00694db0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00694db0(byte param_1,float param_2)

{
  float fVar1;
  int in_ECX;
  
  fVar1 = param_2;
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    if (1.0 < param_2) {
      param_2 = 1.0;
    }
    if (0.0 <= param_2) {
      if (1.0 < fVar1) {
        fVar1 = 1.0;
      }
    }
    else {
      fVar1 = 0.0;
    }
    if ((param_1 & 1) != 0) {
      *(float *)(in_ECX + 0x1b4) = fVar1;
    }
    if ((param_1 & 2) != 0) {
      *(float *)(in_ECX + 0x1b8) = fVar1;
    }
    if ((param_1 & 4) != 0) {
      *(float *)(in_ECX + 0x1bc) = fVar1;
    }
    if ((param_1 & 8) != 0) {
      *(float *)(in_ECX + 0x1c0) = fVar1;
    }
    if ((param_1 & 0x10) != 0) {
      *(float *)(in_ECX + 0x1c4) = fVar1;
    }
    if ((param_1 & 0x20) != 0) {
      *(float *)(in_ECX + 0x1c8) = fVar1;
      return;
    }
  }
  return;
}

