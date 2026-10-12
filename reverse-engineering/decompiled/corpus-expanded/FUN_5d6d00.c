/* Ghidra pseudocode, not original source.
 * ev_2b55f789f1446a783af549e987f50963f158fc34aa4a0a7d53ec4780e4e01d82
 * Entry: 0x5d6d00; label: FUN_005d6d00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005d6d00(void)

{
  int iVar1;
  float10 extraout_ST0;
  
  FUN_006e6b90();
  iVar1 = FUN_006e6b90();
  return (float10)(float)((float10)18.0 /
                         (extraout_ST0 /
                         (float10)(float)(&DAT_029899a0)[0x4000 - iVar1 >> 1 & 0x7fff]));
}

