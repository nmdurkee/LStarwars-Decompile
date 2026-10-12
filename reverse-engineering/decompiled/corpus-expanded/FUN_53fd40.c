/* Ghidra pseudocode, not original source.
 * ev_6ea325c01e2f5d3a14c4ac5085e7df4745032b0fec5c1eb605a31240a38307be
 * Entry: 0x53fd40; label: FUN_0053fd40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053fd40(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  *(float *)(DAT_029838fc + 0xc0) = fVar1;
  *(float *)(DAT_029838fc + 0xbc) = fVar1;
  *(float *)(DAT_029838fc + 0xb8) = fVar1;
  return;
}

