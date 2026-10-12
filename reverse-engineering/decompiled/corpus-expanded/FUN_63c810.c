/* Ghidra pseudocode, not original source.
 * ev_0e84ad542db3be7599677a500db2c2fcd5f6f463504cd13a52c31f7d7facbfa7
 * Entry: 0x63c810; label: FUN_0063c810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0063c810(void)

{
  FUN_005dc050(DAT_029134a4 - _DAT_0080ff3c,DAT_029134a8,DAT_029134ac,_DAT_0080ff3c + DAT_029134a4,
               DAT_029134a8,DAT_029134ac,0xffffffff,_DAT_0080ff3c + DAT_029134a4,DAT_029134a8,
               DAT_029134ac);
  FUN_005dc050(DAT_029134a4,DAT_029134a8 - _DAT_0080ff3c,DAT_029134ac,DAT_029134a4,
               DAT_029134a8 + _DAT_0080ff3c,DAT_029134ac,0xffffffff,DAT_029134a4,
               DAT_029134a8 - _DAT_0080ff3c,DAT_029134ac);
  FUN_005dc050(DAT_029134a4,DAT_029134a8,DAT_029134ac - _DAT_0080ff3c,DAT_029134a4,DAT_029134a8,
               DAT_029134ac + _DAT_0080ff3c,0xffffffff,DAT_029134a4,DAT_029134a8,
               DAT_029134ac - _DAT_0080ff3c);
  return;
}

