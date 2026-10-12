/* Ghidra analysis pseudocode, not original source.
 * ev_7bd2508c4b1dcfad55b57fc1ea402f6c06ab2cec8e89f22b5b974cf1cad07afb
 * Entry: 0x5fa0a0; label: FUN_005fa0a0
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

