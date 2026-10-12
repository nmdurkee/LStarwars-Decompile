/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da840; label: FUN_005da840
 */

undefined4 FUN_005da840(int param_1)

{
  if (*(int *)(param_1 + 0x110) != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x110) + 0x6c);
  }
  return *(undefined4 *)(param_1 + 0x24);
}

