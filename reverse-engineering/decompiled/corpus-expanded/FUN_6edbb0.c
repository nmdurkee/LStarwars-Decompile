/* Ghidra pseudocode, not original source.
 * ev_a061266dd45b392e87f7d3689b136f273b070abf9372dc393200501f91b0ff88
 * Entry: 0x6edbb0; label: FUN_006edbb0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_006edbb0(void)

{
  int unaff_ESI;
  int *unaff_EDI;
  
  if (*unaff_EDI != -2) {
    __security_check_cookie(unaff_EDI[1] + unaff_ESI ^ *(uint *)(*unaff_EDI + unaff_ESI));
  }
  __security_check_cookie(unaff_EDI[3] + unaff_ESI ^ *(uint *)(unaff_EDI[2] + unaff_ESI));
  return;
}

