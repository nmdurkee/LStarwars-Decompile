/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514bb0; label: FUN_00514bb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514bb0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  if ((param_5 != 0) && (*(int *)(param_2 + 0xa4) == param_5)) {
    return (float10)1;
  }
  return (float10)0;
}

