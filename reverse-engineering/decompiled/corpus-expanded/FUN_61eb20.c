/* Ghidra pseudocode, not original source.
 * ev_96058f3856438ce9695e039b323142156f48a7f9b809212960d272b3b98355b0
 * Entry: 0x61eb20; label: FUN_0061eb20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0061eb20(void)

{
  int *in_EAX;
  
  if ((in_EAX[0x13] != 0) && ((*(byte *)(in_EAX + 0x15) & 1) == 0)) {
    *(int *)in_EAX[0x14] = *in_EAX;
    if (*in_EAX != 0) {
      *(int *)(*in_EAX + 4) = in_EAX[0x14];
    }
    *in_EAX = in_EAX[0x13];
    *(int **)(in_EAX[0x13] + 4) = in_EAX;
    in_EAX[0x15] = in_EAX[0x15] | 1;
  }
  return;
}

