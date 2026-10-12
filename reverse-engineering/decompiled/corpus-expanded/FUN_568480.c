/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x568480; label: FUN_00568480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00568480(int param_1,float *param_2,float param_3,int param_4)

{
  undefined4 uVar1;
  float10 fVar2;
  
  *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 1;
  if (0.0 <= param_3) {
    if (param_4 == 0) {
      uVar1 = 0xbf800000;
    }
    else {
      uVar1 = 0x3f800000;
    }
    fVar2 = (float10)FUN_0054fad0(*param_2,uVar1,param_3);
    *param_2 = (float)fVar2;
    *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x54) * *param_2;
    return;
  }
  *(float *)(param_1 + 0x40) = *(float *)(param_1 + 0x54) * *param_2;
  return;
}

