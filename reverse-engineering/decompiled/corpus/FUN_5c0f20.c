/* Ghidra analysis pseudocode, not original source.
 * ev_b6d8a17c6b3263d4647da1f5b2d8de4c4a67e85657c53f6d05a13f18932cfd90
 * Entry: 0x5c0f20; label: FUN_005c0f20
 */

float10 FUN_005c0f20(void)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = FUN_006e6b90();
  return (float10)(((float)(&DAT_029899a0)[iVar1 + 1U & 0x7fff] - (float)(&DAT_029899a0)[iVar1]) *
                   (float)(extraout_ST0 - (float10)iVar1) + (float)(&DAT_029899a0)[iVar1]);
}

