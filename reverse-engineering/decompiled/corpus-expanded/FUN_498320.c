/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x498320; label: FUN_00498320
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00498320(int param_1)

{
  char cVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  cVar1 = *(char *)(param_1 + 0x7b5);
  if (cVar1 == '*') {
    iVar2 = FUN_006e6b90();
    return (float10)((float)(extraout_ST0 - (float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff]) *
                     0.5 * *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x88) * 0.5);
  }
  if (cVar1 == '6') {
    iVar2 = FUN_006e6b90();
    return (float10)((float)(extraout_ST0_00 - (float10)(float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff])
                     * 0.5 * *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x88));
  }
  if ((((cVar1 == ':') && ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0)) && (DAT_0087af5c != 0)) &&
     (*(int *)(PTR_DAT_00802c54 + 300) == DAT_0087af5c)) {
    iVar2 = FUN_006e6b90();
    return (float10)((float)(&DAT_029899a0)[iVar2 >> 1 & 0x7fff] *
                    *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x88));
  }
  return (float10)0;
}

