/* Ghidra pseudocode, not original source.
 * ev_77fef26266fe5967585df020e38eccd49263e70128ef006db684616fa6a4691c
 * Entry: 0x4850e0; label: FUN_004850e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004850e0(void)

{
  int iVar1;
  
  iVar1 = FUN_006e6b90();
  return (float10)((_DAT_007fc310 - _DAT_007fc314) * (float)(&DAT_029899a0)[iVar1 >> 1 & 0x7fff] +
                  _DAT_007fc314);
}

