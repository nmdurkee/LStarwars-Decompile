/* Ghidra pseudocode, not original source.
 * ev_ba19024e936acaebc8caa887b02629c3d2df1b51d473842281df89ce325ba5c8
 * Entry: 0x548fb0; label: FUN_00548fb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00548fb0(undefined4 *param_1,undefined4 param_2)

{
  float10 fVar1;
  
  param_1[1] = param_2;
  *param_1 = param_2;
  fVar1 = (float10)FUN_005b7d30(param_2,0x3f800000);
  param_1[2] = (float)fVar1;
  param_1[3] = 0;
  return;
}

