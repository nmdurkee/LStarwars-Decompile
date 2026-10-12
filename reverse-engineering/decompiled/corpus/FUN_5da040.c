/* Ghidra analysis pseudocode, not original source.
 * ev_a87feee7af7695e4faccb8ecb31a4746b5bfe0fd365f07d7c1fa60b5e2b82015
 * Entry: 0x5da040; label: FUN_005da040
 */

undefined4 FUN_005da040(float *param_1,float *param_2)

{
  float fVar1;
  float *in_ECX;
  float *in_EDX;
  float *unaff_ESI;
  float *unaff_EDI;
  
  if ((((*unaff_ESI <= *in_ECX) || (unaff_ESI[1] <= in_ECX[1])) ||
      (*unaff_EDI < *in_EDX != (*unaff_EDI == *in_EDX))) ||
     (unaff_EDI[1] < in_EDX[1] != (unaff_EDI[1] == in_EDX[1]))) {
    return 0;
  }
  if (*in_EDX <= *in_ECX) {
    fVar1 = *in_ECX;
  }
  else {
    fVar1 = *in_EDX;
  }
  *param_1 = fVar1;
  if (in_EDX[1] <= in_ECX[1]) {
    fVar1 = in_ECX[1];
  }
  else {
    fVar1 = in_EDX[1];
  }
  param_1[1] = fVar1;
  if (*unaff_EDI <= *unaff_ESI) {
    fVar1 = *unaff_EDI;
  }
  else {
    fVar1 = *unaff_ESI;
  }
  *param_2 = fVar1;
  if (unaff_ESI[1] < unaff_EDI[1]) {
    param_2[1] = unaff_ESI[1];
    return 1;
  }
  param_2[1] = unaff_EDI[1];
  return 1;
}

