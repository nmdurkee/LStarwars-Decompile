/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f5950; label: FUN_004f5950
 */

uint FUN_004f5950(void)

{
  int *in_EAX;
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = FUN_004f5880();
  iVar3 = *in_EAX;
  while (iVar3 - 2U < 0x14) {
    switch(iVar3 - 2U) {
    case 2:
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = uVar1 * iVar3;
      break;
    case 3:
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = (int)uVar1 / iVar3;
      break;
    case 4:
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = (int)uVar1 % iVar3;
      break;
    default:
      goto switchD_004f5977_caseD_5;
    case 0x10:
      FUN_004f5380();
      uVar2 = FUN_004f5880();
      uVar1 = (uint)(uVar1 == uVar2);
      break;
    case 0x11:
      FUN_004f5380();
      uVar2 = FUN_004f5880();
      uVar1 = (uint)(uVar1 != uVar2);
      break;
    case 0x12:
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = (uint)((int)uVar1 < iVar3);
      break;
    case 0x13:
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = (uint)(iVar3 < (int)uVar1);
      break;
    case 0x14:
                    /* WARNING: This code block may not be properly labeled as switch case */
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = (uint)((int)uVar1 <= iVar3);
      break;
    case 0x15:
                    /* WARNING: This code block may not be properly labeled as switch case */
      FUN_004f5380();
      iVar3 = FUN_004f5880();
      uVar1 = (uint)(iVar3 <= (int)uVar1);
    }
    iVar3 = *in_EAX;
  }
switchD_004f5977_caseD_5:
  return uVar1;
}

