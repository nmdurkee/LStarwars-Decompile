/* Ghidra pseudocode, not original source.
 * ev_8c943698e03161dcf7a1afd17c02789bd1a03bc5c571948a550cbb172219f06a
 * Entry: 0x55b6c0; label: FUN_0055b6c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0055b6c0(int param_1)

{
  if ((-1 < param_1) && (param_1 < DAT_0093b278)) {
    return *(undefined4 *)(DAT_0093b270 + param_1 * 4);
  }
  return 0;
}

