/* Ghidra pseudocode, not original source.
 * ev_bc7be5d2efb161f05932d74750e8dc45e0b69234cb4138844184cf2ecf6fb617
 * Entry: 0x5a25c0; label: FUN_005a25c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005a25c0(void)

{
  int in_EAX;
  int in_ECX;
  
  if ((in_EAX != 0) && (in_ECX != 0)) {
    if (in_ECX == *(int *)(in_EAX + 0x10)) {
      *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(*(int *)(in_EAX + 0x10) + 0x78);
    }
    FUN_005a2470();
    return;
  }
  return;
}

