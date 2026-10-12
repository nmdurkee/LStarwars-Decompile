/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x515100; label: FUN_00515100
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00515100(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                    int param_5)

{
  if (((param_5 != 0) || (param_5 = *(int *)(param_2 + 0xa0), param_5 != 0)) &&
     ((*(byte *)(param_5 + 0x2a) & 4) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

