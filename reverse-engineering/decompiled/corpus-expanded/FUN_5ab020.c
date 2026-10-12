/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5ab020; label: FUN_005ab020
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005ab020(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_005aac00(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return (float10)*(float *)(iVar1 + 0x28);
  }
  return (float10)0;
}

