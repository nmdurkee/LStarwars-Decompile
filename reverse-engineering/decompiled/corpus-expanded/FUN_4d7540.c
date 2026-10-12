/* Ghidra pseudocode, not original source.
 * ev_7cce3243898a12dda79e95a496780a4d79cb1010b8a976b902fd46336e9989b6
 * Entry: 0x4d7540; label: FUN_004d7540
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_004d7540(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0xed);
  }
  return 0;
}

