/* Ghidra pseudocode, not original source.
 * ev_5992982d2bd497dd48371876a88a1935c49ce47518269efcef374836dc281717
 * Entry: 0x498480; label: FUN_00498480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00498480(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float10 fVar4;
  
  if (((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x2000) != 0) &&
     (iVar3 = FUN_0055f450(), (*(uint *)(*(int *)(iVar3 + 0x128) + 100) & 0x40000) == 0)) {
    fVar4 = (float10)FUN_00498320(param_1);
    fVar1 = (float)fVar4;
    if ((*(char *)(param_1 + 0x283) == '\a') || (*(char *)(param_1 + 0x283) == '\x10')) {
      return (float10)(*(float *)(param_1 + 0x220) + fVar1);
    }
    fVar2 = *(float *)(param_1 + 0x21c);
    if (fVar2 != 2e+06) {
      if ((*(float *)(param_1 + 0x220) != 2e+06) && (fVar2 < *(float *)(param_1 + 0x220))) {
        fVar2 = *(float *)(param_1 + 0x220);
      }
      if (*(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa8) == 0.0) {
        return (float10)(fVar2 + *(float *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x28) +
                        fVar1);
      }
      return (float10)(fVar2 + *(float *)(*(int *)(PTR_DAT_00802c54 + 0x128) + 0xa8) + fVar1);
    }
  }
  return (float10)2e+06;
}

