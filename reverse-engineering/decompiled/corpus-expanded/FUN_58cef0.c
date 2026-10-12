/* Ghidra pseudocode, not original source.
 * ev_9931c233bc23f2b366e36cd20edde6ea49582f2b0a176997d8924d6b396dfde7
 * Entry: 0x58cef0; label: FUN_0058cef0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

