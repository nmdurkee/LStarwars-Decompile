/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a2300; label: FUN_005a2300
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a2300(void)

{
  int in_ECX;
  int *in_EDX;
  
  *in_EDX = in_ECX * 0x80 + (*in_EDX + 0x7fU & 0xffffff80);
  return;
}

