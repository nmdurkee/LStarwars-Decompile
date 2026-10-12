/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x619ce0; label: FUN_00619ce0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00619ce0(void)

{
  int *piVar1;
  int in_EAX;
  
  piVar1 = (int *)(in_EAX + 0x150);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 < 0) {
    *(uint *)(in_EAX + 0x150) = (-(uint)((*(byte *)(in_EAX + 0x164) & 2) != 0) & 2) + 3;
  }
  return;
}

