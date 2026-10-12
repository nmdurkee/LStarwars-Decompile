/* Ghidra analysis pseudocode, not original source.
 * ev_6696c20a63c48b02c48d5a5db7e1958972e2427aa057f5485eee4f348cd6e250
 * Entry: 0x5c2760; label: FUN_005c2760
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

