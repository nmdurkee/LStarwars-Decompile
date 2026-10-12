/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53fb70; label: FUN_0053fb70
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0053fb70(undefined4 param_1)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_004f8100(param_1);
  *(float *)(DAT_029838fc + 0x90) = ABS((float)fVar1);
  return;
}

