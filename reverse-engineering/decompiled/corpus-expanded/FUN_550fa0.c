/* Ghidra pseudocode, not original source.
 * ev_9398ef22b4c43c044c1b187060a2935e0b1d1dc3bbb9f543c9cb1dd758ae788c
 * Entry: 0x550fa0; label: FUN_00550fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00550fa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_00550f10(param_1,param_2,param_3);
  fVar2 = (float10)FUN_00550f10(param_1,param_4,param_5);
  return (float10)(float)((float10)(float)fVar1 / (fVar2 + (float10)(float)fVar1));
}

