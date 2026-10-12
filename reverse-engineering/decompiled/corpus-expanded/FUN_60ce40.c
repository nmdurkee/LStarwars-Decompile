/* Ghidra pseudocode, not original source.
 * ev_0c11dca3c01e2e078e91e20b90f08271c2558dc41f56def09ad2bffabccf1687
 * Entry: 0x60ce40; label: FUN_0060ce40
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0060ce40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006e85b0(*(int *)(in_ECX + 4));
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}

