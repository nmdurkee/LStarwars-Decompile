/* Ghidra analysis pseudocode, not original source.
 * ev_7d8e2999f2f8a3752dbaff0aac6d4e5497e59d04af9d3c1072d39c32106cee2b
 * Entry: 0x5d1860; label: FUN_005d1860
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d1860(void)

{
  undefined4 *puVar1;
  
  DAT_009738d4 = 0;
  puVar1 = &DAT_0096d9e4;
  do {
    *puVar1 = puVar1 + 2;
    puVar1 = puVar1 + 3;
  } while ((int)puVar1 < 0x96dcd8);
  _DAT_0096dcd8 = 0;
  DAT_009738dc = &DAT_0096d9e0;
  DAT_009738d8 = 0;
  DAT_00963e04 = 0;
  DAT_0095fbbc = 0;
  DAT_0096e534 = 0;
  DAT_0096d8f4 = 0;
  _DAT_0096e56c = 0;
  return;
}

