/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x693ba0; label: FUN_00693ba0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00693ba0(void)

{
  int in_ECX;
  
  if (in_ECX != 0) {
    return (float10)*(float *)(in_ECX + 0x1ac);
  }
  return (float10)1;
}

