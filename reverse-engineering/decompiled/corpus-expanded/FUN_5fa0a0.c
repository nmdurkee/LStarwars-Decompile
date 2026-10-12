/* Ghidra pseudocode, not original source.
 * ev_742d340bc2a041ef5ff6078bdc4a89a7f4acdb81012c0f9f5c92fd03ca8daa18
 * Entry: 0x5fa0a0; label: FUN_005fa0a0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005fa0a0(void)

{
  int *unaff_ESI;
  
  if (unaff_ESI == (int *)0x0) {
    FUN_006e5700(0);
    FUN_006e5290(0);
    DAT_02854c18 = 0;
    DAT_02854c1c = 0;
  }
  else {
    if (DAT_02854c18 != *unaff_ESI) {
      FUN_006e5700(*unaff_ESI);
      DAT_02854c18 = *unaff_ESI;
    }
    if (DAT_02854c1c != unaff_ESI[1]) {
      FUN_006e5290(unaff_ESI[1]);
      DAT_02854c1c = unaff_ESI[1];
      return;
    }
  }
  return;
}

