/* Ghidra pseudocode, not original source.
 * ev_7276cf5459c3a9dffdf587356793051a25fc8e8e56315bddbf7c475a739cc847
 * Entry: 0x61a150; label: FUN_0061a150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061a150(int param_1,int param_2)

{
  int *in_EAX;
  int *in_ECX;
  
  *in_ECX = (int)*(short *)(param_1 + 0x16);
  *in_EAX = (int)*(short *)(param_2 + 0x16);
  if (in_ECX == in_EAX) {
    *in_ECX = (int)*(char *)(param_1 + 0x14);
    *in_EAX = (int)*(char *)(param_2 + 0x14);
    *in_ECX = (int)*(char *)(param_1 + 0x13);
    *in_EAX = (int)*(char *)(param_2 + 0x13);
    *in_ECX = (int)*(char *)(param_1 + 0x12);
    *in_EAX = (int)*(char *)(param_2 + 0x12);
    *in_ECX = (int)*(char *)(param_1 + 0x11);
    *in_EAX = (int)*(char *)(param_2 + 0x11);
    *in_ECX = (int)*(char *)(param_1 + 0x10);
    *in_EAX = (int)*(char *)(param_2 + 0x10);
  }
  return;
}

