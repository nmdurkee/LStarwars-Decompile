/* Ghidra analysis pseudocode, not original source.
 * ev_6abf8ab4ca62df3d34ad8936d98d3e0ff06655f6d2b2d7dbe0f57931c7009014
 * Entry: 0x557690; label: FUN_00557690
 */

void FUN_00557690(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x58) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(in_EAX + 0x10);
  *(undefined4 *)(in_EAX + 0x2c) = *(undefined4 *)(in_EAX + 0x14);
  *(undefined4 *)(in_EAX + 0x30) = *(undefined4 *)(in_EAX + 0x18);
  FUN_005a0c20(*(undefined4 *)(in_EAX + 0x34),(undefined4 *)(in_EAX + 0x28),in_EAX + 0x58);
  return;
}

