/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514e20; label: FUN_00514e20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514e20(int param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  if ((((param_3 != 0) && (param_5 != 0)) && (param_1 != 0)) &&
     ((int)*(short *)(param_3 + 0x124) ==
      (param_5 - *(int *)(*(int *)(*(int *)(param_1 + 0x10) + 8) + 0x7c)) / 0x5c)) {
    return (float10)1;
  }
  return (float10)0;
}

