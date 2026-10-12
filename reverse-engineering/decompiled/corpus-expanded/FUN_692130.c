/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x692130; label: FUN_00692130
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00692130(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_02924b10)[iVar1] != 0) {
      FUN_0068ea00(iVar1);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}

