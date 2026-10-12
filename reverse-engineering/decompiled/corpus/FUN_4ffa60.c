/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ffa60; label: FUN_004ffa60
 */

int FUN_004ffa60(void)

{
  if (DAT_0092124c < 0xd) {
    DAT_0092124c = DAT_0092124c + 1;
    InitializeCriticalSection((LPCRITICAL_SECTION)(&DAT_0091ef70 + DAT_0092124c * 0x18));
    return DAT_0092124c;
  }
  return 0;
}

