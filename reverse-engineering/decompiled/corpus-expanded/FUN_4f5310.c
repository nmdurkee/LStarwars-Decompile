/* Ghidra pseudocode, not original source.
 * ev_afcbc9daecc4d4a2b146ef6b9891ec5ae66b352999eedb1b1bbc487287b5378a
 * Entry: 0x4f5310; label: FUN_004f5310
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

int FUN_004f5310(void)

{
  int iVar1;
  char in_CL;
  int iVar2;
  
  iVar2 = (int)in_CL;
  iVar1 = iVar2 + -0x30;
  switch(iVar2) {
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    goto switchD_004f5322_caseD_30;
  default:
    iVar1 = 0;
switchD_004f5322_caseD_30:
    return iVar1;
  case 0x41:
  case 0x42:
  case 0x43:
  case 0x44:
  case 0x45:
  case 0x46:
    return iVar2 + -0x37;
  case 0x61:
  case 0x62:
  case 99:
  case 100:
  case 0x65:
  case 0x66:
    return iVar2 + -0x57;
  }
}

