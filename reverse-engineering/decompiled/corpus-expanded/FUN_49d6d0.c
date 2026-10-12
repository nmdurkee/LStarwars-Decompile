/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49d6d0; label: FUN_0049d6d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0049d6d0(int param_1)

{
  if (DAT_00802818 != -1) {
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined1 *)(param_1 + 0x7b5) = 0x4f;
    *(undefined4 *)(param_1 + 0x784) = 0x3ecccccd;
    *(undefined2 *)(param_1 + 0x7aa) = 0x93;
    *(undefined1 *)(param_1 + 0x7b3) = 0;
    *(undefined4 *)(param_1 + 0x798) = 0;
    return 1;
  }
  return 0;
}

