/* Ghidra analysis pseudocode, not original source.
 * ev_32b79db0f23450a9ff94a1f71da0489d6fe83df38c9fcaa5c40c5fee2e58dea2
 * Entry: 0x698e70; label: FUN_00698e70
 */

void FUN_00698e70(void)

{
  if (DAT_02972bf4 != (void *)0x0) {
    if ((DAT_02972be8 != (void *)0x0) && (DAT_02972bf0 != 0)) {
      _memcpy(DAT_02972bf4,DAT_02972be8,DAT_02972bf0 * 2);
    }
    if (DAT_02972c24 != (HANDLE)0x0) {
      SetEvent(DAT_02972c24);
    }
    if (DAT_02972c34 != (int *)0x0) {
      (**(code **)(*DAT_02972c34 + 0x44))(DAT_02972c34);
    }
    FUN_00698cc0();
    return;
  }
  return;
}

