/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ffa60; label: FUN_004ffa60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

