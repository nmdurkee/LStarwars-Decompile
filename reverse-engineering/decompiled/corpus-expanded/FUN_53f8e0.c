/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53f8e0; label: FUN_0053f8e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0053f8e0(float param_1,int param_2,int *param_3)

{
  float10 fVar1;
  
  fVar1 = (float10)param_1;
  if (param_3 != (int *)0x0) {
    if (fVar1 < (float10)*(float *)(param_2 + 0x18)) {
      return (float10)*(float *)(param_2 + 0x18);
    }
    if ((*(int *)(*(char *)(param_2 + 1) * 0x13c + 0x14 + *param_3) != 0) &&
       ((float10)*(float *)(param_2 + 0xc) < fVar1)) {
      fVar1 = (float10)*(float *)(param_2 + 0xc);
    }
  }
  return fVar1;
}

