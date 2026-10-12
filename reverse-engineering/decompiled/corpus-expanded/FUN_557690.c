/* Ghidra pseudocode, not original source.
 * ev_b0367b6b7ea93641fa3f234a6a49c94b930ee723d26ca433ffbeb1a06357d05a
 * Entry: 0x557690; label: FUN_00557690
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

