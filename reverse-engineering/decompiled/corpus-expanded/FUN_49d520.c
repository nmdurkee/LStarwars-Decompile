/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49d520; label: FUN_0049d520
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049d520(int param_1,undefined4 param_2)

{
  if (*(char *)(param_1 + 0x7b5) == ']') {
    *(undefined4 *)(param_1 + 0x778) = param_2;
  }
  return;
}

