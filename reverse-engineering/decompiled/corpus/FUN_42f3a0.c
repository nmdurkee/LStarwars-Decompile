/* Ghidra analysis pseudocode, not original source.
 * ev_f77d0ac966a5398976b96c42189a5c308704a96dca5e44da054727b198f01d57
 * Entry: 0x42f3a0; label: FUN_0042f3a0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042f3a0(int param_1,int param_2)

{
  int iVar1;
  
  if ((DAT_00951b50 == 0) || (param_2 == 0)) {
    DAT_00856c08 = param_1;
    iVar1 = FUN_0054fa60();
    DAT_007f3b14 = (int)(iVar1 + (iVar1 >> 0x1f & 0x7fffU)) >> 0xf;
    FUN_0054a3e0(PTR_DAT_008021b4,0x3fc00000,0,1);
    DAT_00925398 = 1;
    if (((&DAT_0093d7f0)[DAT_007f3b14] == 0) ||
       ((*(byte *)((&DAT_0093d7f0)[DAT_007f3b14] + 0x1fc) & 0x80) == 0)) {
      DAT_007f3b14 = (uint)(DAT_007f3b14 == 0);
    }
    _DAT_0086e71c = 0;
    FUN_00509830(10,0xffffffff,0xffffffff);
    FUN_00560b40();
    if (param_1 == 3) {
      FUN_00681f40();
      return;
    }
  }
  return;
}

