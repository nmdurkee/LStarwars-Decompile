/* Ghidra pseudocode, not original source.
 * ev_5f11e12836052333f8ad93b61631d5915def4fdf8e192d080659a6ddfc49976b
 * Entry: 0x695540; label: FUN_00695540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00695540(float param_1)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar2 = (float10)0;
  fVar1 = (float10)param_1;
  if (fVar1 < fVar2 != (fVar1 == fVar2)) {
    return (float10)-100.0;
  }
  if ((float10)1 < fVar1 != ((float10)1 == fVar1)) {
    return fVar2;
  }
  fVar2 = (float10)FUN_005be790(param_1);
  return (float10)(float)(fVar2 * (float10)20.0);
}

