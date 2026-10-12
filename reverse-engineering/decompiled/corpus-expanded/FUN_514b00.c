/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514b00; label: FUN_00514b00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514b00(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0xa8) != 0) {
    return (float10)1;
  }
  return (float10)0;
}

