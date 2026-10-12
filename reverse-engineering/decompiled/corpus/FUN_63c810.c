/* Ghidra analysis pseudocode, not original source.
 * ev_b2f72df0dabe11c9bc7c22be1245d6bb58dcd22f440da2427165c0dad76f7a14
 * Entry: 0x63c810; label: FUN_0063c810
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

