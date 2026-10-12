/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x5667a0; label: FUN_005667a0
 */

bool FUN_005667a0(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x50e8) = 0;
  *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0x7fU & 0xffffff80;
  iVar1 = FUN_00552670((uint *)(param_1 + 0x104),param_1 + 0x108,0x8000);
  *(int *)(param_1 + 0x50e8) = iVar1;
  return iVar1 != 0;
}

