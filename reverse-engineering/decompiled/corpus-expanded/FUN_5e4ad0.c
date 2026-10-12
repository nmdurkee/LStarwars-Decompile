/* Ghidra pseudocode, not original source.
 * ev_a87fd181e19a595ed696a9e48a76c3177ea695d31392ba84c3867c15109a72c3
 * Entry: 0x5e4ad0; label: FUN_005e4ad0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e4ad0(void)

{
  int in_EAX;
  
  *(uint *)(in_EAX + 0x44) = *(uint *)(in_EAX + 0x44) | 0x10;
  *(undefined4 *)(in_EAX + 0x54) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x58) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x5c) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x70) = 0x3f800000;
  *(uint *)(in_EAX + 0x40) = *(uint *)(in_EAX + 0x40) & 0xbf9e2fd0 | 0x3f962010;
  return;
}

