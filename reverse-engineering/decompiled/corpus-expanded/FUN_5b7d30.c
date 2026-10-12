/* Ghidra pseudocode, not original source.
 * ev_ef3b2a8ba8bea7724eb7ddbe17370c631fd0c0f4e2170ed1a1745c7d6977e716
 * Entry: 0x5b7d30; label: FUN_005b7d30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005b7d30(void)

{
  int iVar1;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  iVar1 = FUN_006e6b90();
  return (float10)(float)(extraout_ST1 - extraout_ST0 * (float10)iVar1);
}

