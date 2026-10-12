/* Ghidra pseudocode, not original source.
 * ev_b978e2ca46034d20a029bc1dc30b8253616b522a4771dca24a925efe269276a9
 * Entry: 0x5670a0; label: FUN_005670a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005670a0(int param_1,undefined4 param_2)

{
  float10 fVar1;
  
  if (param_1 != 0) {
    if (*(short *)(param_1 + 0x102) != 0) {
      FUN_0067c8e0((int)*(short *)(param_1 + 0x102),0);
    }
    fVar1 = (float10)FUN_005506f0(0,param_2,0x40a00000,0xffffffff);
    if (*(short *)(param_1 + 0x102) != 0) {
      FUN_0067c8e0((int)*(short *)(param_1 + 0x102),1);
    }
    if ((float)fVar1 != 2e+06) {
      return (float10)((float)fVar1 - 0.0);
    }
  }
  return (float10)0;
}

