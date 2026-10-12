/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746380; label: FUN_00746380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

uint FUN_00746380(byte param_1)

{
  return ((byte)(&DAT_0297daa0)[param_1] & 2) >> 1;
}

