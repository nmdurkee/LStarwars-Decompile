/* Ghidra pseudocode, not original source.
 * ev_ea1530849940888f284d0032d7a98207406f19684b2cf3146fa9fb18feca4f87
 * Entry: 0x4671d0; label: FUN_004671d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004671d0(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x68) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x10);
  *(undefined4 *)(in_EAX + 0x20) = *(undefined4 *)(in_EAX + 0x14);
  *(undefined4 *)(in_EAX + 0x24) = *(undefined4 *)(in_EAX + 0x18);
  FUN_005a0c20(*(undefined4 *)(in_EAX + 0x28),(undefined4 *)(in_EAX + 0x1c),in_EAX + 0x68);
  return;
}

