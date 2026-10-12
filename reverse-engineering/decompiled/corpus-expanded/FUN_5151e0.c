/* Ghidra pseudocode, not original source.
 * ev_4714664d6c5f2259a523d26cd0174cb8c61105d62f6b481c865dbf2c57a769ff
 * Entry: 0x5151e0; label: FUN_005151e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

float10 FUN_005151e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (((param_3 != 0) && (*(int *)(param_3 + 0xe4) != 0)) &&
     ((*(uint *)(param_3 + 0x1e8) & 0x800) != 0)) {
    return (float10)1;
  }
  return (float10)0;
}

