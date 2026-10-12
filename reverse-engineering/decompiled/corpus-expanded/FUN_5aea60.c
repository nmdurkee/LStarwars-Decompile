/* Ghidra pseudocode, not original source.
 * ev_18939eb5636c5080554c34c4c464805d15dff0cc807e45e19880c96644741519
 * Entry: 0x5aea60; label: FUN_005aea60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005aea60(float *param_1,float param_2,int param_3,uint param_4)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined1 local_4;
  
  if (param_3 != 0) {
    local_4 = (undefined1)(int)ROUND(*(float *)(param_3 + 0x5c) * 255.0);
    uVar2 = local_4;
    local_4 = (undefined1)(int)ROUND(*(float *)(param_3 + 0x58) * 255.0);
    uVar1 = CONCAT11(uVar2,local_4);
    local_4 = (undefined1)(int)ROUND(*(float *)(param_3 + 0x54) * 255.0);
    param_4 = (uint)CONCAT21(uVar1,local_4);
  }
  FUN_005dc050(*param_1 - param_2,param_1[1],param_1[2],param_2 + *param_1,param_1[1],param_1[2],
               param_4);
  FUN_005dc050(*param_1,param_1[1] - param_2,param_1[2],*param_1,param_2 + param_1[1],param_1[2],
               param_4);
  FUN_005dc050(*param_1,param_1[1],param_1[2] - param_2,*param_1,param_1[1],param_2 + param_1[2],
               param_4);
  return;
}

