/* Ghidra pseudocode, not original source.
 * ev_14412b1be5fe57fadf021e89e905f73790df496cb317f965435f7dd4228acdda
 * Entry: 0x5a1640; label: FUN_005a1640
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005a1640(int param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  float10 fVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x18) != 0)) {
    if (param_3 == 0) {
      param_3 = FUN_005cfa20(*(int *)(param_1 + 0x18) + 4);
    }
    fVar1 = *(float *)(param_3 + 0x34);
    fVar2 = (float10)FUN_005506f0(0,param_2,0x40a00000,0xffffffff);
    if ((float)fVar2 != 2e+06) {
      return (float10)((float)fVar2 - fVar1);
    }
  }
  return (float10)0;
}

