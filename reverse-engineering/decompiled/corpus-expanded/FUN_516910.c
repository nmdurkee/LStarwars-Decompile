/* Ghidra pseudocode, not original source.
 * ev_8db479debe006dcb1d0ae53ec943fbf75b60233db5d397d4c7fbd4646b77bfb6
 * Entry: 0x516910; label: FUN_00516910
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00516910(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,int param_5,
            int param_6)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  
  if ((((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) && (param_6 != 0)) &&
     ((fVar1 = *(float *)(*(int *)(param_3 + 0xd0) + 0xac),
      *(float *)(param_3 + 0x120) = fVar1 + fVar1, param_5 != 0 &&
      (iVar2 = FUN_004f8b10(*param_4,"default"), iVar2 != 0)))) {
    fVar3 = (float10)FUN_00514920(param_3,param_2,*param_4);
    *(float *)(param_3 + 0x120) = (float)fVar3;
  }
  return 1;
}

