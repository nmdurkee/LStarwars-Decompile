/* Ghidra analysis pseudocode, not original source.
 * ev_40d9be8e3a3402c331433b8a2d08079ac53cd459e8d3bded6c92f46fa7f98a9b
 * Entry: 0x659160; label: FUN_00659160
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00659160(void)

{
  int iVar1;
  
  if (DAT_029620cc == 0) {
    iVar1 = FUN_005be5d0(DAT_00973900);
    _DAT_02961fb4 = ((float)DAT_00973900 - 1.0) / (float)iVar1;
    iVar1 = FUN_005be5d0(DAT_00973904);
    _DAT_02920ac8 = ((float)DAT_00973904 - 1.0) / (float)iVar1;
    if (DAT_029620c8 == 0) {
      iVar1 = FUN_005e4d20(1,0xe);
      *(undefined4 *)(iVar1 + 0x54) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x58) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x5c) = 0x3f800000;
      *(undefined4 *)(iVar1 + 0x70) = 0x3f7fbe77;
      DAT_029620c8 = iVar1;
      *(uint *)(iVar1 + 0x40) = *(uint *)(iVar1 + 0x40) & 0xfffee5c0 | 0x6e500;
      *(undefined2 *)(iVar1 + 0x74) = 1;
      FUN_005e4b00(iVar1);
    }
    DAT_029620cc = 1;
  }
  return;
}

