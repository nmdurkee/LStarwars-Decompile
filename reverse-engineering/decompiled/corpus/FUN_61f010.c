/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61f010; label: FUN_0061f010
 */

void FUN_0061f010(int param_1)

{
  do {
    if (param_1 == 0) {
      return;
    }
    param_1 = *(int *)(param_1 + 0x40);
  } while (param_1 != 0);
  return;
}

