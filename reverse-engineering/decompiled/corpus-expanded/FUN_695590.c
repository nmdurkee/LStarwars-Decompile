/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x695590; label: FUN_00695590
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00695590(float param_1)

{
  float10 fVar1;
  
  if (param_1 < -100.0 != (param_1 == -100.0)) {
    return (float10)0;
  }
  if (!NAN(param_1) && 0.0 < param_1 != (param_1 == 0.0)) {
    return (float10)1;
  }
  fVar1 = (float10)FUN_005be970(param_1 / 20.0);
  return fVar1;
}

