/* Ghidra analysis pseudocode, not original source.
 * ev_fd88e83c03467170e633a7d88452db02a14be58504554e3319fa3a0da483c1d2
 * Entry: 0x4ff100; label: FUN_004ff100
 */

void FUN_004ff100(void)

{
  if (DAT_00921244 == 0) {
    InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_009209c4);
    DAT_00921244 = 1;
  }
  return;
}

