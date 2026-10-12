/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x745120; label: FUN_00745120
 */

void FUN_00745120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_007e9300;
  in_ECX[0x82] = 0;
  FUN_00740e90();
  FUN_00748490();
  FUN_007466e0();
  if ((param_1 & 1) != 0) {
    _free(in_ECX);
  }
  return;
}

