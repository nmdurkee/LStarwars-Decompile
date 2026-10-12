/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2350; label: FUN_005a2350
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2350(void)

{
  int *in_ECX;
  
  *in_ECX = (*in_ECX + 3U & 0xfffffffc) + 0x14;
  return;
}

