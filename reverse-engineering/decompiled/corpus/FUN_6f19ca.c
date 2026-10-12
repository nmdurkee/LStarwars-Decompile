/* Ghidra analysis pseudocode, not original source.
 * ev_89d123adc6bf396b2f6b4ec3563e25957edd0c204114ec20eecbaddaafaf9a77
 * Entry: 0x6f19ca; label: FUN_006f19ca
 */

void FUN_006f19ca(int param_1)

{
  uint in_EAX;
  uint in_ECX;
  
  for (; (in_EAX < in_ECX && (0xfffff < (uint)(param_1 - *(int *)(in_EAX + 0xc))));
      in_EAX = in_EAX + 0x14) {
  }
  return;
}

