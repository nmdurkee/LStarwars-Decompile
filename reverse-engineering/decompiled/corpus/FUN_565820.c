/* Ghidra analysis pseudocode, not original source.
 * ev_3b4ca00fd279b908d0ecc0345d0e63acf8414f1fac0e020351d2be86095d22cc
 * Entry: 0x565820; label: FUN_00565820
 */

void FUN_00565820(undefined4 param_1,undefined4 param_2)

{
  undefined2 uVar1;
  int iVar2;
  
  DAT_0095076c = FUN_005e57f0(param_1,param_2);
  iVar2 = FUN_005e4d40(1);
  uVar1 = (undefined2)DAT_0095076c;
  *(undefined4 *)(iVar2 + 0x70) = 0x3f800000;
  *(undefined2 *)(iVar2 + 0x74) = uVar1;
  DAT_00950660 = iVar2;
  *(undefined2 *)(iVar2 + 0x76) = 0x7fff;
  *(uint *)(iVar2 + 0x40) = *(uint *)(iVar2 + 0x40) & 0xfffee5d1 | 0x6e511;
  *(undefined4 *)(iVar2 + 0xb4) = 0x1000;
  *(undefined4 *)(iVar2 + 200) = 0xffffffff;
  *(undefined1 *)(iVar2 + 0x15c) = 1;
  *(uint *)(iVar2 + 0x1f0) = *(uint *)(iVar2 + 0x1f0) & 0xffffcfff | 0x40800;
  FUN_005e4b00(iVar2);
  DAT_00950748 = 0;
  return;
}

