/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57caa0; label: FUN_0057caa0
 */

void FUN_0057caa0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x148) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(in_EAX + 0x148) & 0x1f));
  }
  if (*(int *)(in_EAX + 0x150) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(in_EAX + 0x150) & 0x1f));
  }
  if (*(int *)(in_EAX + 0x158) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(in_EAX + 0x158) & 0x1f));
  }
  if (*(int *)(in_EAX + 0x160) != -1) {
    DAT_0093b0e4 = DAT_0093b0e4 & ~(1 << ((byte)*(int *)(in_EAX + 0x160) & 0x1f));
  }
  return;
}

