/* Ghidra pseudocode, not original source.
 * ev_713fd5a551a5a644e53628cf932656c6d009da906ec29e05de784cd201c28f1f
 * Entry: 0x65bec0; label: FUN_0065bec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0065bec0(float *param_1,float *param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0065bb50((*param_1 + *param_2) * 0.5,(param_1[1] + param_2[1]) * 0.5,
               (param_1[2] + param_2[2]) * 0.5,(*param_2 - *param_1) * 0.5,
               (param_2[1] - param_1[1]) * 0.5,(param_2[2] - param_1[2]) * 0.5,0,0,0,0,0,param_3,
               param_4);
  return;
}

