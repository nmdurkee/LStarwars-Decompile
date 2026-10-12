/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5f9720; label: FUN_005f9720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f9720(void)

{
  if (DAT_02854bec != (int *)0x0) {
    (**(code **)(*DAT_02854bec + 8))(DAT_02854bec);
    DAT_02854bec = (int *)0x0;
  }
  return;
}

