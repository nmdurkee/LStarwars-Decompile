/* Ghidra pseudocode, not original source.
 * ev_65ca4a665d596d296f41bb3c37f26e684dc272ec4121c3f4d046db6dd8870575
 * Entry: 0x53dc00; label: FUN_0053dc00
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

