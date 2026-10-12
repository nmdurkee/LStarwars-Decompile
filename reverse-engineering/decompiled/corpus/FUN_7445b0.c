/* Ghidra analysis pseudocode, not original source.
 * ev_01db8885f86fbb74a531da5bb10d328a9b146c5a63264b26651b6a27e7cc1924
 * Entry: 0x7445b0; label: FUN_007445b0
 */

undefined4 FUN_007445b0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[3] == 0) {
    uVar2 = FUN_00744430(param_1);
    return uVar2;
  }
  cVar1 = FUN_00744430(param_1);
  if (((cVar1 != '\0') && (param_1 == 0)) && ((*(byte *)(*in_ECX + 0x1b4) & 1) != 0)) {
    return 1;
  }
  return 0;
}

