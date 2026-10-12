/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f990; label: FUN_0053f990
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053f990(undefined4 param_1)

{
  float fVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f8100(param_1);
  fVar1 = (float)fVar2;
  if ((fVar1 < 0.0) || (fVar1 <= *(float *)(DAT_029838fc + 0x74))) {
    fVar1 = *(float *)(DAT_029838fc + 0x74);
  }
  *(float *)(DAT_029838fc + 0x78) = fVar1;
  return;
}

