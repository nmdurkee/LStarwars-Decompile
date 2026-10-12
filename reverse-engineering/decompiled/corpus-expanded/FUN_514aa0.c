/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514aa0; label: FUN_00514aa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514aa0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xd0) != 0)) &&
     ((param_5 != 0 || (param_5 = *(int *)(param_2 + 0xa4), param_5 != 0)))) {
    return (float10)(*(float *)(*(int *)(param_3 + 0xd0) + 0x60) - *(float *)(param_5 + 0x14));
  }
  return (float10)0;
}

