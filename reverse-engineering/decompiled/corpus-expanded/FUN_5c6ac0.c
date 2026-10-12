/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c6ac0; label: FUN_005c6ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c6ac0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_ECX;
  float *in_EDX;
  float *unaff_ESI;
  
  if (in_EDX[2] <= in_ECX[2]) {
    fVar1 = in_ECX[2];
  }
  else {
    fVar1 = in_EDX[2];
  }
  if (in_EDX[1] <= in_ECX[1]) {
    fVar2 = in_ECX[1];
  }
  else {
    fVar2 = in_EDX[1];
  }
  if (*in_EDX <= *in_ECX) {
    fVar3 = *in_ECX;
  }
  else {
    fVar3 = *in_EDX;
  }
  *unaff_ESI = fVar3;
  unaff_ESI[1] = fVar2;
  unaff_ESI[2] = fVar1;
  unaff_ESI[3] = 1.0;
  return;
}

