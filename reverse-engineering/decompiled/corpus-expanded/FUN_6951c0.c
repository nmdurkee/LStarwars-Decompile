/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x6951c0; label: FUN_006951c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006951c0(void)

{
  if (DAT_02962b8c != 0) {
    return (float10)*(float *)(DAT_02962b8c + 0x1ac);
  }
  return (float10)1.0;
}

