/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c8260; label: FUN_005c8260
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

