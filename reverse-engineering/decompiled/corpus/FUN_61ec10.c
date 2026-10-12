/* Ghidra analysis pseudocode, not original source.
 * ev_9121b524f6182e73d65d2cf5b7796f5032c40ac2ecc24e842002b0e6ddc347ec
 * Entry: 0x61ec10; label: FUN_0061ec10
 */

void FUN_0061ec10(int param_1)

{
  int iVar1;
  
  for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 4)) {
    if (*(int *)(iVar1 + 8) == 0x13) {
      FUN_0061eb60(iVar1);
    }
  }
  return;
}

