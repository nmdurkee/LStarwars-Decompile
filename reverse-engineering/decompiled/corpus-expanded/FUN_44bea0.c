/* Ghidra pseudocode, not original source.
 * ev_899eb35a27e8c18144a9bface4dcd684320477ea32232f25bcb19f5ddc9c569a
 * Entry: 0x44bea0; label: FUN_0044bea0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0044bea0(int param_1)

{
  *(uint *)(param_1 + 0x108) = *(uint *)(param_1 + 0x108) & 0xffffbfff | 0x80;
  FUN_0064a740();
  return;
}

