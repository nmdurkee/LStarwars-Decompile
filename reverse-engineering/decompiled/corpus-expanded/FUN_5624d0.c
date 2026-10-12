/* Ghidra pseudocode, not original source.
 * ev_bda4f146c2d51158c85c1388fc7f1b6ba26e1289d7f2ba8cabd91a305fd9300e
 * Entry: 0x5624d0; label: FUN_005624d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
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

