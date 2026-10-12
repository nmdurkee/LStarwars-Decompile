/* Ghidra pseudocode, not original source.
 * ev_40a85160eaccd151253910192404d8aba277d39ac9ab2a88fc5c5de06172d047
 * Entry: 0x4ffac0; label: FUN_004ffac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ffac0(int param_1)

{
  if (param_1 - 1U < 0xc) {
    LeaveCriticalSection((LPCRITICAL_SECTION)(&DAT_0091ef70 + param_1 * 0x18));
  }
  return;
}

