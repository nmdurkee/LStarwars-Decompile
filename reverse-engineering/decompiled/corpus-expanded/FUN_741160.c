/* Ghidra pseudocode, not original source.
 * ev_5ac1ee00c479ad98735f6958677979f6fc8ed4ea1e5106cd7456ee96087ef4e0
 * Entry: 0x741160; label: FUN_00741160
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00741160(void)

{
  int in_EAX;
  
  *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) + 1;
  return;
}

