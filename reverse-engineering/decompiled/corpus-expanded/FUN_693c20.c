/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x693c20; label: FUN_00693c20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00693c20(int param_1)

{
  int in_ECX;
  
  if ((in_ECX != 0) && (DAT_02962b8c != 0)) {
    *(uint *)(in_ECX + 0x1d0) = (uint)(param_1 != 0);
  }
  return;
}

