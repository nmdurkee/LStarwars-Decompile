/* Ghidra pseudocode, not original source.
 * ev_6521300b9938a199c527bda86aad79e1bd40e1a48847beae11455f6dd9ad37ba
 * Entry: 0x623900; label: FUN_00623900
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00623900(float *param_1,byte param_2,byte param_3,byte param_4)

{
  uint uVar1;
  
  uVar1 = ((param_4 | 0xffffff00) << 8 | (uint)param_3) << 8 | (uint)param_2;
  FUN_005dc050(*param_1 - 0.5,param_1[1],param_1[2],*param_1 + 0.5,param_1[1],param_1[2],uVar1);
  FUN_005dc050(*param_1,param_1[1] - 0.5,param_1[2],*param_1,param_1[1] + 0.5,param_1[2],uVar1);
  FUN_005dc050(*param_1,param_1[1],param_1[2] - 0.5,*param_1,param_1[1],param_1[2] + 0.5,uVar1);
  return;
}

