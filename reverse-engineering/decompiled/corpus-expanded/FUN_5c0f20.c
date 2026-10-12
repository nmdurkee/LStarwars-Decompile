/* Ghidra pseudocode, not original source.
 * ev_e061930119eb38dbd4d1e45fa45a2093349cae71e0e7104520800438f1f9aa3c
 * Entry: 0x5c0f20; label: FUN_005c0f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005c0f20(void)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = FUN_006e6b90();
  return (float10)(((float)(&DAT_029899a0)[iVar1 + 1U & 0x7fff] - (float)(&DAT_029899a0)[iVar1]) *
                   (float)(extraout_ST0 - (float10)iVar1) + (float)(&DAT_029899a0)[iVar1]);
}

