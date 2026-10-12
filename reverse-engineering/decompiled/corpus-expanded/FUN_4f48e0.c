/* Ghidra pseudocode, not original source.
 * ev_621a163f2f4eeffab67db0a5a6d80d4261cbfd10193b5f3a01bc1d3544017af8
 * Entry: 0x4f48e0; label: FUN_004f48e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_004f48e0(int param_1)

{
  if ((&DAT_0297e048)[param_1 * 3] != 0) {
    return (&DAT_0297e044)[param_1 * 3];
  }
  return 0xffffffff;
}

