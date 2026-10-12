/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4ef870; label: FUN_004ef870
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

