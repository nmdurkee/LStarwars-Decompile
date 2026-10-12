/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x515270; label: FUN_00515270
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515270(undefined4 param_1,undefined4 param_2,int param_3)

{
  if ((param_3 != 0) && (*(int *)(param_3 + 0xd4) != 0)) {
    return (float10)*(float *)(param_3 + 0xd8);
  }
  return (float10)3.4028235e+38;
}

