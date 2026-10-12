/* Ghidra pseudocode, not original source.
 * ev_27b4776215878f137ff0909fe422d2d71d1f91aa156c4f9d6b43512fc3378c0f
 * Entry: 0x5c6750; label: FUN_005c6750
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_005c6750(undefined4 param_1)

{
  int in_EAX;
  undefined1 in_DL;
  
  **(undefined1 **)(in_EAX + 0x24) = in_DL;
  *(undefined1 *)(*(int *)(in_EAX + 0x24) + 1) = 3;
  *(undefined4 *)(*(int *)(in_EAX + 0x24) + 4) = param_1;
  *(int *)(in_EAX + 0x24) = *(int *)(in_EAX + 0x24) + 0x10;
  return *(int *)(in_EAX + 0x24) + -0x10;
}

