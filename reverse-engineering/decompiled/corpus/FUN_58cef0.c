/* Ghidra analysis pseudocode, not original source.
 * ev_46f409524a34738389d7f31976d6a221d1967ea0058d40007842d66f20536672
 * Entry: 0x58cef0; label: FUN_0058cef0
 */

void FUN_0058cef0(int param_1)

{
  if ((*(uint *)(PTR_PTR_007fb0e4 + *(char *)(param_1 + 0x7b5) * 0x10 + 8) & 0x200000) == 0) {
    if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x94) & 0x40000000) != 0) {
      FUN_0058c4d0();
      return;
    }
    if ((*(uint *)(*(int *)(param_1 + 0x54) + 4) & 0x20000) != 0) {
      FUN_0058c010();
      return;
    }
    FUN_0058c9e0();
  }
  return;
}

