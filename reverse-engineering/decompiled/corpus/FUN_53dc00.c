/* Ghidra analysis pseudocode, not original source.
 * ev_d03c8c013d77d4b4815fe766df72f82b935735dde13e911b202c41b11099d6d0
 * Entry: 0x53dc00; label: FUN_0053dc00
 */

void FUN_0053dc00(void)

{
  float *in_ECX;
  float *in_EDX;
  float *unaff_ESI;
  
  if (*in_ECX < *in_EDX) {
    *in_EDX = *in_ECX;
  }
  if (*unaff_ESI < *in_ECX) {
    *unaff_ESI = *in_ECX;
  }
  if (in_ECX[1] < in_EDX[1]) {
    in_EDX[1] = in_ECX[1];
  }
  if (unaff_ESI[1] < in_ECX[1]) {
    unaff_ESI[1] = in_ECX[1];
  }
  if (in_ECX[2] < in_EDX[2]) {
    in_EDX[2] = in_ECX[2];
  }
  if (unaff_ESI[2] < in_ECX[2]) {
    unaff_ESI[2] = in_ECX[2];
  }
  return;
}

