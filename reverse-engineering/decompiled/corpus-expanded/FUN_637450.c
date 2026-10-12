/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x637450; label: FUN_00637450
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00637450(void)

{
  float fVar1;
  int in_EAX;
  
  if ((*(char *)(in_EAX + 0x79) != -1) || (*(char *)(in_EAX + 0x7a) != -1)) {
    fVar1 = *(float *)(PTR_DAT_0080fe0c + *(char *)(in_EAX + 0x7b) * 4);
    *(float *)(in_EAX + 0x18) = *(float *)(in_EAX + 0x18) + fVar1 * *(float *)(in_EAX + 0x24);
    *(float *)(in_EAX + 0x1c) = *(float *)(in_EAX + 0x28) * fVar1 + *(float *)(in_EAX + 0x1c);
    *(float *)(in_EAX + 0x20) = fVar1 * *(float *)(in_EAX + 0x2c) + *(float *)(in_EAX + 0x20);
  }
  return;
}

