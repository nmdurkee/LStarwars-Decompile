/* Ghidra pseudocode, not original source.
 * ev_0c39cc066d2b612e886b5e8dc629d567ae8f788bfbc7a0ed81832ee74aa3ece0
 * Entry: 0x403630; label: FUN_00403630
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00403630(void)

{
  int in_EAX;
  
  *(undefined1 *)(in_EAX + 0x7b5) = 0x52;
  *(undefined4 *)(in_EAX + 0x77c) = 0;
  *(undefined2 *)(in_EAX + 0x7aa) = 0x9a;
  *(undefined4 *)(in_EAX + 0x784) = 0x3e4ccccd;
  *(undefined4 *)(in_EAX + 0x748) = *(undefined4 *)(in_EAX + 0xc5c);
  *(undefined4 *)(in_EAX + 0x74c) = *(undefined4 *)(in_EAX + 0xc60);
  *(undefined4 *)(in_EAX + 0x750) = 0x3f800000;
  *(undefined4 *)(in_EAX + 0x754) = DAT_0093b0cc;
  *(undefined4 *)(in_EAX + 0x758) = DAT_0093b0d0;
  *(undefined4 *)(in_EAX + 0x75c) = DAT_0093b0d4;
  return;
}

