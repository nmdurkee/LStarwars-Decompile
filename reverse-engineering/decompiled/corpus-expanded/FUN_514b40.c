/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x514b40; label: FUN_00514b40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_00514b40(int param_1)

{
  if ((*(int *)(param_1 + 0x138c) != 0) &&
     ((*(byte *)(*(int *)(*(int *)(param_1 + 0x138c) + 4) + 0x166) & 1) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

