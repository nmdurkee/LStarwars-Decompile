/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746480; label: FUN_00746480
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00746480(uint param_1)

{
  return CONCAT31((int3)((param_1 & 0x4020) >> 8),(param_1 & 0x4020) == 0x4020);
}

