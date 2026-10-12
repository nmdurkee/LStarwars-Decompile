/* Ghidra analysis pseudocode, not original source.
 * ev_8191aeb1a3da19da8f7480131ae46b5e7aabe132901fddc0002d6d5d4eb98622
 * Entry: 0x48b430; label: FUN_0048b430
 */

void FUN_0048b430(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_0093d500) {
    iVar2 = 0;
    iVar1 = DAT_0093d504;
    do {
      if ((*(byte *)(iVar2 + 0x1fc + iVar1) & 1) != 0) {
        FUN_004d22f0(iVar2 + 0xcc4 + iVar1);
        FUN_0055cad0(iVar2 + DAT_0093d504,1);
        iVar1 = DAT_0093d504;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x10d8;
    } while (iVar3 < DAT_0093d500);
  }
  if ((DAT_00803784 != -1) && (DAT_00803784 == DAT_0095121c)) {
    return;
  }
  if (DAT_00955874 == 2) {
    FUN_005936b0(DAT_00856980);
  }
  else if (DAT_00955874 == 1) {
    FUN_005930c0(DAT_00856980);
  }
  DAT_00955874 = 0;
  FUN_0062dfb0(0);
  FUN_0055b7f0();
  FUN_0055b610();
  if (DAT_009248a0 != 0) {
    FUN_005ef880(DAT_009248a0);
  }
  DAT_009248a0 = 0;
  if (DAT_0092489c != 0) {
    FUN_005ef880(DAT_0092489c);
  }
  DAT_0092489c = 0;
  if (DAT_00924898 != 0) {
    FUN_005ef880(DAT_00924898);
  }
  DAT_00924898 = 0;
  FUN_005a8180();
  return;
}

