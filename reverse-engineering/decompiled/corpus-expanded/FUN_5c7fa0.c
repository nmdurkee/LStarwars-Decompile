/* Ghidra pseudocode, not original source.
 * ev_ca420d431c934f8a992b8493b34a08505595e08ff53ba47cba12c20e874b5619
 * Entry: 0x5c7fa0; label: FUN_005c7fa0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

