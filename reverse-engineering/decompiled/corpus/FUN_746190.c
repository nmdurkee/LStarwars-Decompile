/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x746190; label: FUN_00746190
 */

void FUN_00746190(byte param_1)

{
  void *in_ECX;
  
  FUN_00746120();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

