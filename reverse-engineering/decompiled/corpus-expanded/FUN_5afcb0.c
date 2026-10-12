/* Ghidra pseudocode, not original source.
 * ev_6cccc8e135eae3c44bbaa4a7e61ce02c4dd764f80107b645200a09e8a948bf0e
 * Entry: 0x5afcb0; label: FUN_005afcb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined1 FUN_005afcb0(int param_1)

{
  if (param_1 != 0) {
    return *(undefined1 *)(*(int *)(param_1 + 0x128) + 0x109);
  }
  return 0;
}

