/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f5310; label: FUN_004f5310
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

