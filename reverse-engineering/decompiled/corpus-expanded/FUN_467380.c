/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x467380; label: FUN_00467380
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00467380(void)

{
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    FUN_005a11b0(*(undefined4 *)(unaff_ESI + 0x28),0);
    if (*(float *)(unaff_ESI + 0x58) < 0.0) {
      FUN_005a1030(*(undefined4 *)(unaff_ESI + 0x28),
                   *(float *)(unaff_ESI + 0x60) * *(float *)(unaff_ESI + 0x58),0);
      return;
    }
    FUN_005a1030(*(undefined4 *)(unaff_ESI + 0x28),
                 *(float *)(unaff_ESI + 0x5c) * *(float *)(unaff_ESI + 0x58),0);
  }
  return;
}

