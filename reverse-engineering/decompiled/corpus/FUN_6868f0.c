/* Ghidra analysis pseudocode, not original source.
 * ev_58caf276ebc048efa4d646f9d9307ba49b402b8a20e2023011e3c4448b71b628
 * Entry: 0x6868f0; label: FUN_006868f0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006868f0(void)

{
  undefined4 uVar1;
  
  if (DAT_029620cc != 0) {
    uVar1 = FUN_005f8f10(_DAT_029620b0,0);
    uVar1 = FUN_005f8f20(uVar1);
    FUN_005d4300(1,2,1);
    if (0 < DAT_02947d84) {
      FUN_00685770(0,2);
    }
    FUN_0074e9e0(uVar1);
    FUN_005f3950();
    return;
  }
  return;
}

