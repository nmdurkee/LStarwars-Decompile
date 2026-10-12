/* Ghidra analysis pseudocode, not original source.
 * ev_6eb3c0e5a4192d504e77ca733851733d52b37eecab747dc6ff26bd5be7535327
 * Entry: 0x61eb20; label: FUN_0061eb20
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

