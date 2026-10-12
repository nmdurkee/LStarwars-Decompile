/* Ghidra pseudocode, not original source.
 * ev_cd85811e73cbe502a6d015fc1f20588fa81ce6efb8852e42609516c9f2c20483
 * Entry: 0x5154e0; label: FUN_005154e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005154e0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  float10 fVar1;
  undefined1 local_c [12];
  
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    fVar1 = (float10)FUN_005becc0(*(int *)(param_3 + 0xe4) + 0x5c,param_5 + 0x10,local_c);
    return fVar1;
  }
  return (float10)3.4028235e+38;
}

