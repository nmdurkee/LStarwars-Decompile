/* Ghidra pseudocode, not original source.
 * ev_1dc9efed74ce485fa07d0eb4956e717fb8a5e32d65f10374f235b0f400c25ed0
 * Entry: 0x6a11a0; label: FUN_006a11a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_006a11a0(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 < 0) {
    return (float10)-1.0;
  }
  return (float10)CONCAT44(param_3,param_2) / (float10)*(int *)(*(int *)(param_1 + 4) + 8);
}

