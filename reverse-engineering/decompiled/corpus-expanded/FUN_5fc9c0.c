/* Ghidra pseudocode, not original source.
 * ev_f88dcc3d8d52db9817d56bdb32315046821db5231446aa7c2a0f18fee0dcf233
 * Entry: 0x5fc9c0; label: FUN_005fc9c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005fc9c0(undefined4 param_1)

{
  int in_EAX;
  undefined1 in_DL;
  
  **(undefined1 **)(in_EAX + 0x24) = in_DL;
  *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1) = 3;
  *(undefined4 *)(*(int *)(in_EAX + 0x24) + 4) = param_1;
  *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + 0x10;
  return *(int *)(in_EAX + 0x24) + -0x10;
}

