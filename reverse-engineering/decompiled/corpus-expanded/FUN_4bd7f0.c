/* Ghidra pseudocode, not original source.
 * ev_554bacc3f16b6ba5ba2e9bdc745347cbc06d0daeabfbc4224973a16c83b60b9e
 * Entry: 0x4bd7f0; label: FUN_004bd7f0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

byte FUN_004bd7f0(int *param_1)

{
  return *(byte *)(*param_1 + 0xa2) >> 2 & 1;
}

