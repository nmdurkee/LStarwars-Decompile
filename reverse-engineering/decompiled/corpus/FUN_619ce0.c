/* Ghidra analysis pseudocode, not original source.
 * ev_142c6a8c6383f125e012f2efba2eadfa5dbe8b6e60e30e9e06bfa3e419522019
 * Entry: 0x619ce0; label: FUN_00619ce0
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

