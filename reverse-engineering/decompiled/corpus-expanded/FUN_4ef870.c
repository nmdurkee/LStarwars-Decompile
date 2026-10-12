/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4ef870; label: FUN_004ef870
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004ef870(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 8) != 0) {
    *(undefined4 *)(*(int *)(in_EAX + 8) + 4) = *(undefined4 *)(in_EAX + 4);
  }
  if (*(int *)(in_EAX + 4) != 0) {
    *(undefined4 *)(*(int *)(in_EAX + 4) + 8) = *(undefined4 *)(in_EAX + 8);
  }
  return;
}

