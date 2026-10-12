/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619ec0; label: FUN_00619ec0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619ec0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 0x154) - 1;
  *(uint *)(in_ECX + 0x154) = uVar1 & ((int)uVar1 < 0) - 1;
  return;
}

