/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x5666d0; label: FUN_005666d0
 */

bool FUN_005666d0(int param_1)

{
  ushort uVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x50c4) = 0;
  *(undefined4 *)(param_1 + 0x50bc) = 0;
  uVar1 = *(ushort *)(*(int *)(param_1 + 0x128) + 0xdc);
  if (uVar1 == 0) {
    return false;
  }
  iVar2 = FUN_00552670(param_1 + 0x104,param_1 + 0x108,(uint)uVar1 << 8);
  *(int *)(param_1 + 0x50c4) = iVar2;
  return iVar2 != 0;
}

