/* Ghidra pseudocode, not original source.
 * ev_e036c7439cd20116919e592c8e070cde3540a7375a0b02133844a56e359aaeed
 * Entry: 0x49dc60; label: FUN_0049dc60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0049dc60(int param_1,int param_2)

{
  *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xfffeafff;
  *(undefined4 *)(param_1 + 0x77c) = 0;
  *(undefined1 *)(param_1 + 0xe32) = 0;
  *(undefined1 *)(param_1 + 0x7b5) = 0;
  *(undefined1 *)(param_1 + 0x7b8) = 0;
  *(undefined2 *)(param_1 + 0x7aa) = 6;
  *(undefined1 *)(param_1 + 0x7b9) = 2;
  *(undefined4 *)(param_1 + 0xd1c) = 0;
  if ((param_2 == 0) && (*(int *)(*(int *)(*(int *)(param_1 + 0x50) + 0xc) + 0x124) != 0)) {
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) & 0xffff7fff;
    *(undefined4 *)(param_1 + 0x6c) =
         *(undefined4 *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x2c);
    *(undefined2 *)(param_1 + 0x7aa) = 0x49;
    FUN_00547f30(param_1,0);
  }
  else {
    *(undefined1 *)(param_1 + 0x7b5) = 0xff;
  }
  if (*(char *)(*(int *)(*(int *)(param_1 + 0x54) + 0x24) + 0x116) == '\x02') {
    FUN_00547f30(param_1,1);
  }
  return;
}

