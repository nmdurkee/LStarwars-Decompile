/* Ghidra pseudocode, not original source.
 * ev_5ac1ee00c479ad98735f6958677979f6fc8ed4ea1e5106cd7456ee96087ef4e0
 * Entry: 0x741050; label: FUN_00741050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_00741050(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) - *(int *)(in_ECX + 0xc);
}

