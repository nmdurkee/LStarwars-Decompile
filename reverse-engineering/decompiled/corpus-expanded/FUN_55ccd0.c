/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55ccd0; label: FUN_0055ccd0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0055ccd0(int param_1)

{
  int iVar1;
  float fVar2;
  
  iVar1 = *(int *)(param_1 + 0x54);
  *(float *)(param_1 + 0xa4) = *(float *)(iVar1 + 0x2c) * *(float *)(param_1 + 0xa8);
  fVar2 = *(float *)(param_1 + 0xffc) * *(float *)(param_1 + 0xa8);
  *(float *)(param_1 + 0xac) = fVar2;
  *(float *)(param_1 + 0xb0) = fVar2 * *(float *)(param_1 + 0x1004);
  *(float *)(param_1 + 0xb4) =
       (*(float *)(iVar1 + 0x38) - *(float *)(iVar1 + 0x34)) * *(float *)(param_1 + 0xff8);
  return;
}

