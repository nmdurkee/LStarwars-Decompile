/* Ghidra pseudocode, not original source.
 * ev_3cc3478cfa8c26bd4fafca5bd3c3e065fb7e5c3537b7c6265584e6b0ffbf613e
 * Entry: 0x636220; label: FUN_00636220
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00636220(undefined4 param_1)

{
  int in_EAX;
  undefined4 in_EDX;
  
  if (*(int *)(in_EAX + 0x48) < 3) {
    *(undefined4 *)(in_EAX + 0x30 + *(int *)(in_EAX + 0x48) * 4) = in_EDX;
    *(undefined4 *)(in_EAX + 0x3c + *(int *)(in_EAX + 0x48) * 4) = param_1;
    *(int *)(in_EAX + 0x48) = *(int *)(in_EAX + 0x48) + 1;
  }
  return;
}

