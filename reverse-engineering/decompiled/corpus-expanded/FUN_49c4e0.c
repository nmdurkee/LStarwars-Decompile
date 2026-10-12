/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49c4e0; label: FUN_0049c4e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049c4e0(int param_1)

{
  if ((*(int *)(param_1 + 0x790) != 0) && ((*(byte *)(param_1 + 0xe24) & 1) != 0)) {
    FUN_004364e0(*(int *)(param_1 + 0x790),2,0);
    *(undefined4 *)(param_1 + 0x790) = 0;
  }
  if ((*(char *)(param_1 + 0x7b5) == '9') || (*(char *)(param_1 + 0x7b5) == '8')) {
    *(undefined4 *)(param_1 + 0x790) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  *(uint *)(param_1 + 0xe24) = *(uint *)(param_1 + 0xe24) & 0xfffffffe;
  return;
}

