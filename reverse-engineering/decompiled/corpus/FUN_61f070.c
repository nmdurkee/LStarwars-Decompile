/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f070; label: FUN_0061f070
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

