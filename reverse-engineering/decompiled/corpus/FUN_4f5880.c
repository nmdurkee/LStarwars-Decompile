/* Ghidra analysis pseudocode, not original source.
 * ev_bdb17253d8eceafb8feb22cd0a23bb82c1f6b43d5fe47ab3712e26b834ea25e8
 * Entry: 0x4f5880; label: FUN_004f5880
 */

uint FUN_004f5880(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  switch(*param_1) {
  case 1:
    FUN_004f5380();
    iVar2 = FUN_004f5880(param_1);
    return -iVar2;
  default:
    FUN_004ef790();
    return 0;
  case 5:
    break;
  case 7:
    return 1;
  case 8:
    FUN_004f5380();
    return param_1[1];
  case 0xb:
    FUN_004f5380();
    uVar1 = FUN_004f5880(param_1);
    return ~uVar1;
  case 0xf:
    FUN_004f5380();
    iVar2 = FUN_004f5880(param_1);
    return (uint)(iVar2 == 0);
  }
  FUN_004f5380();
  uVar1 = FUN_004f5ab0(param_1);
  if (*param_1 != 6) {
    FUN_004ef790();
  }
  FUN_004f5380();
  return uVar1;
}

