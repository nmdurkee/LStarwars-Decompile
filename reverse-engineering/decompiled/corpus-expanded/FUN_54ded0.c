/* Ghidra pseudocode, not original source.
 * ev_5bb5b933382fccff1624478c543279b7c4a11e7bde078056255cfa1f5dfacd26
 * Entry: 0x54ded0; label: FUN_0054ded0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_0054ded0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xee);
  }
  return 0;
}

