/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x744430; label: FUN_00744430
 */

undefined4 FUN_00744430(undefined4 param_1)

{
  int *in_ECX;
  
  switch(param_1) {
  case 0:
    return 1;
  case 1:
    if (((*(byte *)(*in_ECX + 0x1b8) & 0x40) != 0) && (*(char *)(*in_ECX + 0x44) != -1)) {
      return 1;
    }
    break;
  case 2:
    if (((*(byte *)(*in_ECX + 0x1b8) & 0x80) != 0) && (*(char *)(*in_ECX + 0x45) != -1)) {
      return 1;
    }
    break;
  case 3:
    if (((*(uint *)(*in_ECX + 0x1b8) & 0x100) != 0) && (*(char *)(*in_ECX + 0x46) != -1)) {
      return 1;
    }
    break;
  default:
    return 0;
  }
  return 0;
}

