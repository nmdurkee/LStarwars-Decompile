/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e4e80; label: FUN_005e4e80
 */

undefined4 FUN_005e4e80(int param_1)

{
  undefined4 uVar1;
  int extraout_ECX;
  
  if ((0x17 < param_1) || (param_1 < 0)) {
    FUN_005c12e0();
    param_1 = extraout_ECX;
  }
  uVar1 = DAT_00973ff4;
  DAT_00973ff4 = param_1;
  return uVar1;
}

