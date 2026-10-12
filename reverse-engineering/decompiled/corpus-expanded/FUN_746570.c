/* Ghidra pseudocode, not original source.
 * ev_d27b225b9633e56be6d9d5c2be7adfa4268b9e50bf259b668c645e1f15e7124d
 * Entry: 0x746570; label: FUN_00746570
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00746570(void)

{
  int in_ECX;
  
  return *(undefined4 *)(&DAT_007e9458 + *(int *)(in_ECX + 4) * 4);
}

