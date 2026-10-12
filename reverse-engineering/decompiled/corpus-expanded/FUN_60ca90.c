/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60ca90; label: FUN_0060ca90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_0060ca90(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x18)) {
    return *(int *)(in_ECX + 4);
  }
  return in_ECX + 4;
}

