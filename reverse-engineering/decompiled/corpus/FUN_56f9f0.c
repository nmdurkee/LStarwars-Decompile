/* Ghidra analysis pseudocode, not original source.
 * ev_c11631b0b0a1045a7d98640a93ba67d08ac61cae21ea073376eab243577db9e4
 * Entry: 0x56f9f0; label: FUN_0056f9f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f9f0(int param_1,int param_2)

{
  ushort uVar1;
  
  _DAT_00950f5c = 0xc0c00000;
  if ((-1 < param_1) && (param_1 < DAT_00951360)) {
    uVar1 = *(ushort *)(param_1 * 0x9c + 0x7a + DAT_00951354);
    if (((uVar1 & 0x200) != 0) &&
       ((*(uint *)(param_2 * 0x130 + 100 + DAT_00951b78) & 0x400000) == 0)) {
      _DAT_00950f5c = 0;
      return;
    }
    if ((uVar1 & 1) != 0) {
      _DAT_00950f5c = 0xc1a00000;
    }
  }
  return;
}

