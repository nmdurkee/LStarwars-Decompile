/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x566730; label: FUN_00566730
 */

bool FUN_00566730(int param_1)

{
  int iVar1;
  
  *(undefined4 *)(param_1 + 0x50c8) = 0;
  *(undefined4 *)(param_1 + 0x50c0) = 0;
  if (*(short *)(*(int *)(param_1 + 0x128) + 0xda) == 0) {
    return false;
  }
  *(uint *)(param_1 + 0x104) = *(int *)(param_1 + 0x104) + 0xfU & 0xfffffff0;
  iVar1 = FUN_00552670((uint *)(param_1 + 0x104),param_1 + 0x108,
                       (uint)*(ushort *)(*(int *)(param_1 + 0x128) + 0xda) * 0x114);
  *(int *)(param_1 + 0x50c8) = iVar1;
  return iVar1 != 0;
}

