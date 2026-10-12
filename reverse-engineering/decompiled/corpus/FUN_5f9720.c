/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5f9720; label: FUN_005f9720
 */

void FUN_005f9720(void)

{
  if (DAT_02854bec != (int *)0x0) {
    (**(code **)(*DAT_02854bec + 8))(DAT_02854bec);
    DAT_02854bec = (int *)0x0;
  }
  return;
}

