/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x5667f0; label: FUN_005667f0
 */

undefined4 FUN_005667f0(int param_1)

{
  undefined4 uVar1;
  
  FUN_005666d0(param_1);
  FUN_00566730(param_1);
  *(undefined4 *)(param_1 + 0x50e8) = 0;
  *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0x7fU & 0xffffff80;
  uVar1 = FUN_00552670((uint *)(param_1 + 0x104),param_1 + 0x108,0x8000);
  *(undefined4 *)(param_1 + 0x50e8) = uVar1;
  return *(undefined4 *)(param_1 + 0x50c8);
}

