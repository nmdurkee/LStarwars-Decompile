/* Ghidra analysis pseudocode, not original source.
 * ev_cbd55f1ba69fad8b2a2e6ea0f242e13091651791652d5df1d4b2dffa4b1da1c0
 * Entry: 0x49f800; label: FUN_0049f800
 */

undefined4 FUN_0049f800(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = 0xffffffff;
  uVar2 = 0xffffffff;
  if (param_1 == 0x65) {
    uVar1 = 0;
    uVar2 = 0x66;
  }
  else if (param_1 == 0x67) {
    uVar1 = 1;
    uVar2 = 0x68;
  }
  else if (param_1 == 0x69) {
    uVar1 = 2;
    uVar2 = 0x6a;
  }
  else if (param_1 == 0x6b) {
    uVar1 = 3;
    uVar2 = 0x6c;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = uVar2;
  }
  return uVar1;
}

