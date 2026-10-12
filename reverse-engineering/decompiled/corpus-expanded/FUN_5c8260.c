/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c8260; label: FUN_005c8260
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c8260(void)

{
  float fVar1;
  float fVar2;
  float *in_EAX;
  float *unaff_ESI;
  float *unaff_EDI;
  
  fVar1 = in_EAX[1];
  fVar2 = in_EAX[2];
  *unaff_ESI = *in_EAX;
  unaff_ESI[1] = fVar1;
  unaff_ESI[2] = fVar2;
  unaff_ESI[3] = 0.0;
  FUN_005b3b30();
  unaff_ESI[3] = 1.0;
  unaff_ESI[3] = -(unaff_EDI[2] * unaff_ESI[2] +
                  *unaff_EDI * *unaff_ESI + unaff_EDI[1] * unaff_ESI[1]);
  return;
}

