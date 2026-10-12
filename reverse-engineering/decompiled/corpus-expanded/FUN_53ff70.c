/* Ghidra pseudocode, not original source.
 * ev_6ea325c01e2f5d3a14c4ac5085e7df4745032b0fec5c1eb605a31240a38307be
 * Entry: 0x53ff70; label: FUN_0053ff70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053ff70(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_029838fc + 0xd0) = (float)fVar1;
  *(ushort *)(DAT_029838fc + 0x68) = *(ushort *)(DAT_029838fc + 0x68) | 0x400;
  return;
}

