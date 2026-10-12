/* Ghidra pseudocode, not original source.
 * ev_d41a9e73f582863d0d1c8c52ad55b427a61509ce0f65a786388b60a63b819da3
 * Entry: 0x540ac0; label: FUN_00540ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00540ac0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  float10 fVar1;
  
  if (param_1 == 0) {
    fVar1 = (float10)FUN_00540670(param_2,param_3,param_4,param_5);
    return fVar1;
  }
  if (param_1 != 1) {
    return (float10)0;
  }
  fVar1 = (float10)FUN_005407d0(param_2,param_3,param_4,param_5);
  return fVar1;
}

