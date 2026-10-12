/* Ghidra pseudocode, not original source.
 * ev_608779b64e90f57b93ecbf13df65bed39f2d483d8cb24d2405739ebf49354e95
 * Entry: 0x57caa0; label: FUN_0057caa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

