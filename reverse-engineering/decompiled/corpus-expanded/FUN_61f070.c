/* Ghidra pseudocode, not original source.
 * ev_001bae53855cec29a6ea9336ea11e15c4e661e4f9ad78accb3ab39ae90f716fb
 * Entry: 0x61f070; label: FUN_0061f070
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061f070(void)

{
  int in_EAX;
  
  do {
    if (in_EAX == 0) {
      return;
    }
    in_EAX = *(int *)(in_EAX + 0x3c);
  } while (in_EAX != 0);
  return;
}

