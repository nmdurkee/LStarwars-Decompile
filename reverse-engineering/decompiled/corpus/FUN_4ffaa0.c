/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ffaa0; label: FUN_004ffaa0
 */

void FUN_004ffaa0(int param_1)

{
  if (param_1 - 1U < 0xc) {
    EnterCriticalSection((LPCRITICAL_SECTION)(&DAT_0091ef70 + param_1 * 0x18));
  }
  return;
}

