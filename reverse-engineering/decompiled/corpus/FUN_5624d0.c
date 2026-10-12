/* Ghidra analysis pseudocode, not original source.
 * ev_ac23db90eeef6e74a247016e3a520edd15ea735459e03f7d3b11d2be7c6b3fca
 * Entry: 0x5624d0; label: FUN_005624d0
 */

undefined4 FUN_005624d0(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  
  if (DAT_00802838 != -1) {
    *(char *)(param_1 + 0x7b5) = (char)DAT_00802838;
    *(undefined1 *)(param_1 + 0x7b8) = 4;
    uVar1 = DAT_00804ce0;
    *(undefined4 *)(param_1 + 0x77c) = 0;
    *(undefined2 *)(param_1 + 0x7aa) = uVar1;
    if ((*(byte *)(param_1 + 0x1fc) & 0x80) != 0) {
      *(uint *)(param_1 + 0xeec) = *(uint *)(param_1 + 0xeec) | 0x800;
    }
    *(undefined4 *)(param_1 + 0x6c) = param_2;
    *(undefined1 *)(param_1 + 0x7b9) = 0;
    FUN_00547f30(param_1,4);
    FUN_0054a850(**(undefined4 **)(param_1 + 0xca4),0x3f000000,0);
    *(uint *)(param_1 + 0x7bc) = *(uint *)(param_1 + 0x7bc) | 0x10000;
    return 1;
  }
  return 0;
}

