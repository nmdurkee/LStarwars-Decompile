/* Ghidra analysis pseudocode, not original source.
 * ev_b8818be8b1d42ca956a2be2988b1e4995be83f28184475e50ebee2db8720dc05
 * Entry: 0x55f650; label: FUN_0055f650
 */

void FUN_0055f650(int param_1)

{
  if (*(int *)(param_1 + 0x13c) != 0) {
    if ((DAT_00951c34 == 0) && (*(int *)(*(int *)(param_1 + 0x13c) + 0x110) == 0)) {
      FUN_005d9030();
      FUN_005eeb30(*(undefined4 *)(param_1 + 0x13c));
      FUN_0055f560(param_1,0);
    }
    FUN_00601df0(*(undefined4 *)(param_1 + 0x13c));
    if (*(int *)(*(int *)(param_1 + 0x13c) + 0x110) != 0) {
      FUN_0055f560(param_1,0);
    }
  }
  return;
}

