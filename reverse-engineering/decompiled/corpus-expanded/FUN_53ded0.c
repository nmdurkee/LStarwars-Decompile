/* Ghidra pseudocode, not original source.
 * ev_e871a9194485fbee58f0df50382f75afe220c1b708bcc123f17e0b18b93cb2b9
 * Entry: 0x53ded0; label: FUN_0053ded0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_0053ded0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_0053de40(param_1,param_2,param_3);
  fVar2 = (float10)FUN_0053de40(param_1,param_4,param_5);
  return (float10)(float)((float10)(float)fVar1 / (fVar2 + (float10)(float)fVar1));
}

