/* Ghidra pseudocode, not original source.
 * ev_48a43e34cbe01c2505cf9aa17d334aa99da5a34bf6b6757d2f19fc15fd1d9710
 * Entry: 0x49b960; label: FUN_0049b960
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049b960(int param_1)

{
  if (*(char *)(param_1 + 0x7b5) != ',') {
    FUN_0055e4a0(param_1,1);
    FUN_0055e4e0(param_1 + 0x6c4);
    *(undefined4 *)(param_1 + 0x754) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x10bc) = *(undefined4 *)(param_1 + 0x5c);
    *(undefined4 *)(param_1 + 0x758) = *(undefined4 *)(param_1 + 0x60);
    *(undefined4 *)(param_1 + 0x10c0) = *(undefined4 *)(param_1 + 0x60);
    *(undefined1 *)(param_1 + 0x7b5) = 0x2c;
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    *(undefined4 *)(param_1 + 0x75c) = *(undefined4 *)(param_1 + 100);
    *(undefined4 *)(param_1 + 0x10c4) = *(undefined4 *)(param_1 + 100);
  }
  return;
}

