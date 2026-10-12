/* Ghidra analysis pseudocode, not original source.
 * ev_58a5325186d3cd5df394779674731c2ac26ad2d4ec877fc6396ce44c5c65b6b5
 * Entry: 0x5c7fa0; label: FUN_005c7fa0
 */

void FUN_005c7fa0(void)

{
  float *unaff_ESI;
  float *unaff_EDI;
  
  FUN_005b3920();
  FUN_005b3b30();
  unaff_EDI[3] = 1.0;
  unaff_EDI[3] = -(unaff_EDI[2] * unaff_ESI[2] +
                  *unaff_ESI * *unaff_EDI + unaff_EDI[1] * unaff_ESI[1]);
  return;
}

