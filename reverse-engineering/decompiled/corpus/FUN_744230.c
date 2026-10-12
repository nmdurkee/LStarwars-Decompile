/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x744230; label: FUN_00744230
 */

undefined4 FUN_00744230(void)

{
  int *in_ECX;
  
  if (((*(uint *)(*in_ECX + 0x13c) & 0x30000) != 0) &&
     ((*(uint *)(*in_ECX + 0x13c) & 0x400000) == 0)) {
    return 1;
  }
  return 0;
}

