/* Ghidra pseudocode, not original source.
 * ev_dfa41b6c39560a6d4e303a9a42849e633890ea31aa955743b15917c3077a3c9c
 * Entry: 0x5c2760; label: FUN_005c2760
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005c2760(void)

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

